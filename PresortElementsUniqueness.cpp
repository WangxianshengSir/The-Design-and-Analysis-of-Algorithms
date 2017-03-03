/*
 *PresortElementsUniqueness(A[0...n])
 //先对数组排序来解决元素唯一性问题
 //输入：n个可排序元素构成的数组A[0...n-1]
 //输出：如果A没有相等的元素，返回true，否则返回false
 对数组A排序
 for i<-0 to n-1 do
    if A[i]=A[i+1] return false
 return true
 *
 */
