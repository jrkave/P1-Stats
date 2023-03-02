#include <iostream>
#include "p1_library.h"
#include "stats.h"
using namespace std;

string filename;
string column_name;
void print(const vector<double> &v) {
  summarize(v);
  cout << endl;
  cout << "count = " << count(v) << endl;
  cout << "sum = " << sum(v) << endl;
  cout << "mean = " << mean(v) << endl;
  cout << "stdev = " << stdev(v) << endl;
  cout << "median = " << median(v) << endl;
  cout << "mode = " << mode(v) << endl;
  cout << "min = " << min(v) << endl;
  cout << "max = " << max(v) << endl;
  cout << "  0th percentile = " << percentile(v, 0) << endl;
  cout << "  25th percentile = " << percentile(v, .25) << endl;
  cout << "  50th percentile = " << percentile(v, .50) << endl;
  cout << "  75th percentile = " << percentile(v, .75) << endl;
  cout << "  100th percentile = " << percentile(v, 1) << endl;
}

int main() {
  cout << "enter a filename" << endl;
  cin >> filename;
  cout << "enter a column name" << endl;
  cin >> column_name;
  vector<double> v = extract_column(filename, column_name);
  cout << "reading column " << column_name << " from " << filename << endl;
  print(v);
  return 0;
}
