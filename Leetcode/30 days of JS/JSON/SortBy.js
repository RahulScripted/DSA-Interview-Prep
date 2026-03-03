// Given an array arr and a function fn, return a sorted array sortedArr. You can assume fn only returns numbers and those numbers determine the sort order of sortedArr. sortedArr must be sorted in ascending order by fn output.





const sortBy = (arr, fn) => arr.sort((a, b) => fn(a) - fn(b));