int binary_search(int arr[], int left, int right, int x) {
  if(right >= left) {
    int cur = left + (right - left) / 2;
    if(arr[cur] == x)
      return cur;
    if(arr[cur] > x)
      return binary_search(arr, left, cur - 1, x);
    return binary_search(arr, cucr + 1, right, x);
  }
}

int finPos(int arr[], int x) {
  int left = 0, right = 0;
  int val = arr[0];
  while(val < x) {
    left = right;
    right *= 2;
    val = arr[right]
  }
  return binary_search(arr, left, right, x)
}
