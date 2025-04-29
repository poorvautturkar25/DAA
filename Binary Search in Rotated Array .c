#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
		{
            return mid;
        }

        if (nums[left] <= nums[mid])
		{

            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        else
		{

            if (target > nums[mid] && target <= nums[right])
			{
                left = mid + 1;
            }
			else
			{
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int numsSize, target,i;

    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    int nums[numsSize];
    printf("Enter the elements of the rotated array (sorted but rotated):\n");
    for ( i = 0; i < numsSize; i++)
	{
        scanf("%d", &nums[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = search(nums, numsSize, target);
    if (result != -1)
	{
        printf("Target %d found at index %d.\n", target, result);
    }
	else
	{
        printf("Target %d not found.\n", target);
    }

    return 0;
}

