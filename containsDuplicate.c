int comp(const void *elem1, const void *elem2) {
  return *((int *)elem1) - *((int *)elem2);
}

bool containsDuplicate(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(*nums), comp);

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1]) {
      return true;
    }
  }
  return false;
}
