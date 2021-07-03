class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        dist= [abs(i- x) for i in arr]
        r= dist.index(min(dist))+ 1
        l= r- 2
        a= [arr[r- 1]]
        for i in range(k- 1):
            if r== len(arr):
                for j in range(k- i- 1):
                    a.append(arr[l- j])
                break
            if l== -1:
                for j in range(k- i- 1):
                    a.append(arr[r+ j])
                break
            if dist[r]< dist[l]:
                a.append(arr[r])
                r= r+ 1
            else:
                a.append(arr[l])
                l= l- 1
        return sorted(a)
        