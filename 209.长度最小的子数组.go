/*
 * @lc app=leetcode.cn id=209 lang=golang
 *
 * [209] 长度最小的子数组
 */

package leetcode

// @lc code=start
func minSubArrayLen(target int, nums []int) int {
	res := len(nums) + 1
	sum := 0
	for start, end := 0, 0; end < len(nums); end++ {
		sum += nums[end]
		for sum >= target {
			if end-start+1 == 1 { // HINT: 提前终止
				return 1
			}
			if end-start+1 < res {
				res = end - start + 1
			}
			sum -= nums[start]
			start++
		}
	}

	return res % (len(nums) + 1)
}

// @lc code=end
