#include <array>
#include <iostream>

template <typename T, std::size_t N, typename Compare>
void insertion_sort(std::array<T, N>& arr, Compare cmp) {
  for (int i = 1; i < N; ++i) {
    const T key = arr[i];
    int j = i - 1;
    for (; j >= 0 && cmp(key, arr[j]); --j) arr[j + 1] = arr[j];
    arr[j + 1] = key;

    // debug output
    for (auto num : arr) std::cout << num << " ";
    std::cout << '\n';
  }
}

template <typename T, std::size_t N, typename Compare>
void shell_sort(std::array<T, N>& arr, Compare cmp) {
  for (int d = N / 2; d > 0; d /= 2) {
    for (int i = d; i < N; ++i) {
      const T key = arr[i];
      int j = i - d;
      for (; j >= 0 && cmp(key, arr[j]); j -= d) arr[j + d] = arr[j];
      arr[j + d] = key;
    }

    // debug output
    for (auto num : arr) std::cout << num << " ";
    std::cout << '\n';
  }
}

template <typename T, std::size_t N, typename Compare>
void selection_sort(std::array<T, N>& arr, Compare cmp) {
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (cmp(arr[j], arr[i])) std::swap(arr[i], arr[j]);
    }

    // debug output
    for (auto num : arr) std::cout << num << " ";
    std::cout << '\n';
  }
}

template <typename T, std::size_t N, typename Compare>
void bubble_sort(std::array<T, N>& arr, Compare cmp) {
  for (int i = 0; i < N - 1; ++i) {
    for (int j = 1; j < N; ++j) {
      if (cmp(arr[j], arr[j - 1])) std::swap(arr[j], arr[j - 1]);
    }

    // debug output
    for (auto num : arr) std::cout << num << " ";
    std::cout << '\n';
  }
}

template <typename T, std::size_t N, typename Compare>
void heap_sort(std::array<T, N>& arr, Compare cmp) {
  auto heapify = [&arr, &cmp](const auto self, int i, int n) -> void {
    int l = 2 * i + 1, r = 2 * i + 2, largest = i;
    if (l < n && cmp(arr[largest], arr[l])) largest = l;
    if (r < n && cmp(arr[largest], arr[r])) largest = r;

    if (largest != i) {
      std::swap(arr[i], arr[largest]);
      self(self, largest, n);
    }
  };

  auto build_heap = [&arr, &heapify](int n) {
    for (int i = n / 2 - 1; i >= 0; --i) heapify(heapify, i, n);
  };

  build_heap(N);
  for (int i = N - 1; i > 0; --i) {
    std::swap(arr[0], arr[i]);
    heapify(heapify, 0, i);
  }
}

template <typename T, std::size_t N, typename Compare>
void merge_sort(std::array<T, N>& arr, Compare cmp, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  merge_sort(arr, cmp, l, mid);
  merge_sort(arr, cmp, mid + 1, r);
  std::array<T, N> tmp;
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (cmp(arr[i], arr[j]))
      tmp[k++] = arr[i++];
    else
      tmp[k++] = arr[j++];
  }
  while (i <= mid) tmp[k++] = arr[i++];
  while (j <= r) tmp[k++] = arr[j++];
  for (i = l; i <= r; ++i) arr[i] = tmp[i];

  // debug output
  for (auto num : arr) std::cout << num << " ";
  std::cout << '\n';
}

template <typename T, std::size_t N, typename Compare>
void quick_sort(std::array<T, N>& arr, Compare cmp, int l, int r) {
  if (l >= r) return;
  int i = l, j = r;
  T key = arr[l];
  while (i < j) {
    while (i < j && cmp(key, arr[j])) --j;
    if (i < j) arr[i++] = arr[j];
    while (i < j && cmp(arr[i], key)) ++i;
    if (i < j) arr[j--] = arr[i];
  }
  arr[i] = key;

  // debug output
  for (auto num : arr) std::cout << num << " ";
  std::cout << '\n';

  quick_sort(arr, cmp, l, i - 1);
  quick_sort(arr, cmp, i + 1, r);
}

int main() {
  std::array nums{81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};

  auto cmp = [](int a, int b) -> bool { return a < b; };

  // insertion_sort(nums, cmp);
  // shell_sort(nums, cmp);
  // selection_sort(nums, cmp);
  // bubble_sort(nums, cmp);
  heap_sort(nums, cmp);
  // merge_sort(nums, cmp, 0, nums.size() - 1);
  // quick_sort(nums, cmp, 0, nums.size() - 1);

  for (auto num : nums) std::cout << num << " ";
  std::cout << std::endl;
  return 0;
}