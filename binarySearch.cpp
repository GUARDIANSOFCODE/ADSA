int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
