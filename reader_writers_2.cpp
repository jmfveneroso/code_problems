// =====================================================
// Book: Elements of programming interviews
// Problem 18.6: Reader writers 2
// =====================================================

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class ReaderWriter {
  static mutex r_m;
  static int x;
  static int read_count;

 public:
  void Write(int new_x) {
    lock_guard<mutex> lock(r_m);
    this_thread::sleep_for(chrono::milliseconds(100));
    x = new_x;
  }

  void Read() {
    {
      lock_guard<mutex> lock(r_m);
      read_count++;
    }
  
    this_thread::sleep_for(chrono::milliseconds(20)); 

    {
      lock_guard<mutex> lock(r_m);
      cout << "Reading " << x << " from thread " << this_thread::get_id() << endl;
      read_count--;
    }
  }
};

mutex ReaderWriter::r_m;
int ReaderWriter::x = 0;
int ReaderWriter::read_count = 0;

int main() {
  ReaderWriter reader_writer;

  thread t1([&] {
    reader_writer.Read();
    reader_writer.Read();
    reader_writer.Read();
  });

  thread t2([&] {
    reader_writer.Write(13);
    reader_writer.Read();
  });

  thread t3([&] {
    reader_writer.Read();
    reader_writer.Write(51);
    reader_writer.Read();
  });

  t1.join();
  t2.join();
  t3.join();

  reader_writer.Read();
  return 0;
}
