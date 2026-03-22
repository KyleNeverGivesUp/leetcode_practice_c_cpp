
"""
Maximum diff between two number in one array
"""


def count_floor(num):
    if num == 2: ret = 2
    if num == 1: ret = 1
    if num > 2:
        ret = count_floor(num - 1) + count_floor(num - 2)
    return ret


if __name__ == "__main__":
    a = [9,8,5,6,4,7]
    dp = [0,0,0,0,0,0]
    bf = [0,0,0,0,0,0]
    local_max = [0,0,0,0,0,0]
    global_max_num = 0
    local_max_num = 0
    curr_diff = 0
    for k in range(1, len(a)):
    
        j = k - 1
        while j >= 0:

            if bf[k] < a[j] - a[k]:
                bf[k] = a[j] - a[k]
            j-=1

        # dp[k] = max( a[k-1] - a[k], a[k-1] - a[k] + dp[k-1])
    
        curr_diff = a[k-1] - a[k]
        local_max_num = max(curr_diff, local_max_num + curr_diff)
        global_max_num = max(global_max_num, local_max_num)
        dp[k] = max( curr_diff, global_max_num)

    print(bf)
    print(dp)
    