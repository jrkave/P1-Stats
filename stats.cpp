// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>

using namespace std;

vector<pair<double, int>> summarize(vector<double> v) {
  assert(!v.empty());
  int freq = 0;
  map<double, int> map;
  pair<double, int> p;
  vector<pair<double, int>> pairs;
  double currValue = 0;

  for (int i = 0; i < v.size(); i++) {
    currValue = v[i];
    for (int j = 0; j < v.size(); j++) {
        if (v[j] == currValue) {
            freq++;
        }
    }
    map.insert({v[i], freq});
    freq = 0; // reset
  }
  for (auto ele : map) {
    p = {ele.first, ele.second};
    pairs.push_back(p);
  }

  // Print
  cout << "Summary (value: frequency)" << endl;
  for (int i = 0; i < pairs.size(); i++) {
    cout << pairs[i].first << ": " << pairs[i].second << endl;
  }

  return pairs;
}

int count(vector<double> v) {
  return (v.size());
}

double sum(vector<double> v) {
  assert(!v.empty());
  double sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return sum;
}

double mean(vector<double> v) {
  assert(!v.empty());
  double sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return (sum / v.size());
}


double median(vector<double> v) {
  assert(!v.empty());
  sort(v);
  int middle;
  if (v.size() % 2 != 0) { 
    middle = v.size() / 2;
    return v[middle];
  }
  else {
    middle = (v.size() / 2) - 1; // 1 2 3 4
    double median;
    median = (v[middle] + v[(middle - 1)] / 2);
    return median;
  }   
}


double mode(vector<double> v) {
  assert(!v.empty());
  map<double, int> map; // item : frequency
  double mode;
  double currValue = 0;
  int freq = 0;
  for (int i = 0; i < v.size(); i++) {
    currValue = v[i];
    for (int j = 0; j < v.size(); j++) {
        if (v[j] == currValue) {
            freq++; // count how many times currValue is in v
        }
    }
    map.insert({v[i], freq}); // store as item, frequency pair
    freq = 0; // reset currCount
    }

    // iterate through map 
    for (auto ele : map) {
        if (ele.second > freq) { // check if curr freq > last freq checked
            mode = ele.first;
            freq = ele.second; // reset freq 
        }
    }
    return mode;
}


double min(vector<double> v) {
  assert(!v.empty());
  int min = v[0];
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < min) {
        min = v[i];
    }
  }
  return min;
}


double max(vector<double> v) {
  assert(!v.empty());
  int max = v[0];
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > max) {
        max = v[i];
    }
  }
  return max;
}


double stdev(vector<double> v) {
  assert(v.size() >= 2);
  double sum = 0;
  double sumSquares = 0;
  double mean = 0;
  double stdev;
  int i;

  // find average
  for (i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  mean = (sum / v.size());

  // find sum of squares
  for (i = 0; i < v.size(); i++) {
    sumSquares += (pow((v[i] - mean), 2));
  }

  // find stdev
  stdev = sqrt(sumSquares / (v.size() - 1));
  return stdev;
}


double percentile(vector<double> v, double p) {
  assert(!v.empty());
  assert(p >= 0 && p <= 1);
  sort(v);

  double n = static_cast<double>(v.size());
  double rank = (p * (n - 1) + 1);

  // Interpolate to estimate the value at the desired percentile
  if (rank == 1) {
      return v[0];
  } else if (rank == n) {
      return v[n - 1];
  } else {
      int k = static_cast<int>(std::floor(rank));
      double d = rank - k;
      return v[k - 1] + d * (v[k] - v[k - 1]);
  }
}
