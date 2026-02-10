// Given a function fn, return a new function that is identical to the original function except that it ensures fn is called at most once.

//     1 - The first time the returned function is called, it should return the same result as fn.
//     2 - Every subsequent time it is called, it should return undefined.





var once = function(fn) {
    let called = false;
    return function(...args){
        if(!called){
            called = true;
            return fn(...args);
        }

        return undefined;
    }
}


let fn = (a,b,c) => (a + b + c)
let oneFn = once(fn);

console.log(oneFn(1,2,3));
console.log(oneFn(2,3,4));