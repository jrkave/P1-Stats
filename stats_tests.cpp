/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

// Add prototypes for test functions
void test_summarize_small_data_set();
void test_count_small_data_set();
void test_sum_small_data_set();
void test_mean_small_data_set();
void test_median_small_data_set();
void test_mode_small_data_set();
void test_min_small_data_set();
void test_max_small_data_set();
void test_stdev_small_data_set();
void test_percentile_small_data_set();
void test_all();

int main() {
  // Call test function
  test_all();
  return 0;
}

// Testing summarize
void test_summarize_small_data_set() {
  cout << "test_summarize_small_data_set" << endl;

  vector<double> data = {6, 7, 8, 9};
  vector<pair<double, int>> pairs = summarize(data);
  pair<double, int> pair = {7, 1};
  assert(pairs[1] == pair);

  cout << "PASS!" << endl;
}

// Testing count
void test_count_small_data_set() {
  cout << "test_count_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(count(data) == 3);

  cout << "PASS!" << endl;
}

// Testing sum
void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Testing mean
void test_mean_small_data_set() {
  cout << "test_mean_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(mean(data) == 2);

  cout << "PASS!" << endl;
}

// Testing median
void test_median_small_data_set() {
  cout << "test_median_small_data_set" << endl;
  vector<double> data;

  // size 1 vector
  data.push_back(3);
  assert(median(data) == 3);

  // odd size vector
  data.clear();
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  assert(median(data) == 2);

  // even size vector
  data.clear();
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  assert(median(data) == 2.5);

  cout << "PASS!" << endl;
}


// Testing mode
void test_mode_small_data_set() {
  cout << "test_mode_small_data_set" << endl;
  
  vector<double> data;
  data = {1, 2, 3};
  assert(mode(data) == 1);
  data.clear();
  data = {1, 1, 2, 2};
  assert(mode(data) == 1);
  data.clear();
  data = {2, 2, 1, 1};
  assert(mode(data) == 1);
  data.clear();
  data = {1, 2, 1, 2, 2};
  assert(mode(data) == 2);

  cout << "PASS!" << endl;
}

// Testing minimum
void test_min_small_data_set() {
  cout << "test_min_small_data_set" << endl;
  
  vector<double> data;
  data = {1, 2, -1};
  assert(min(data) == -1);

  cout << "PASS!" << endl;
}

// Testing maximum
void test_max_small_data_set() {
  cout << "test_max_small_data_set" << endl;

  vector<double> data;
  data = {1, 2, 56};
  assert(max(data) == 56);

  cout << "PASS!" << endl;
}

// Testing std dev
void test_stdev_small_data_set() {
  cout << "test_stdev_small_data_set" << endl;

  vector<double> data;
  data = {6, 7, 8, 9, 10};
  assert(floor(stdev(data)) == 1);

  cout << "PASS!" << endl;
}


// Testing percentile
void test_percentile_small_data_set() {
  cout << "test_percentile_small_data_set" << endl;
  
  vector<double> data = {6, 7, 8, 9, 10};
  assert(percentile(data, .75) == 9);
  assert(percentile(data, .25) == 7);
  assert(percentile(data, 0) == 6);
  assert(percentile(data, 1) == 10);
  assert(percentile(data, .5) == 8);

  cout << "PASS!" << endl;
}

void test_all() {
  test_summarize_small_data_set();
  test_count_small_data_set();
  test_sum_small_data_set();
  test_mean_small_data_set();
  test_median_small_data_set();
  test_mode_small_data_set();
  test_min_small_data_set();
  test_max_small_data_set();
  test_stdev_small_data_set();
  test_percentile_small_data_set();
}