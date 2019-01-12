def merge(region_list):

    total_region = []

    if not test_list:
        return []
    for region in region_list:
        if not total_region:
            total_region = region_list[0]
            continue
        # min
        if total_region[0] > region[0]:
            total_region[0] = region[0]
        # max
        if total_region[1] < region[1]:
            total_region[1] = region[1]

    return total_region

if __name__ == '__main__':
    test_list = [[1,3],[2,6],[8,10],[15,18]]
    test_list2 = [[1,4],[4,5]]

    l1 = merge(test_list)
    l2 = merge(test_list2)
    print l1, l2