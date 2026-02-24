// Given an object or an array, return if it is empty.

//     1 - An empty object contains no key-value pairs.
//     2 - An empty array contains no elements.

// You may assume the object or array is the output of JSON.parse.






var isEmpty = function(obj) {
    if (Array.isArray(obj)) return obj.length === 0;
    else return Object.keys(obj).length === 0;
};