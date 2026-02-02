// Write a function createCounter. It should accept an initial integer init. It should return an object with three functions. The three functions are:

    // 1 - increment() increases the current value by 1 and then returns it.
    // 2 - decrement() reduces the current value by 1 and then returns it.
    // 3 - reset() sets the current value to init and then returns it.



type ReturnObj = {
    increment: () => number;
    decrement: () => number;
    reset: () => number;
};

function createCounter(init: number): ReturnObj {
    let val = init;
    return {
        increment() {
            return ++val;
        },
        decrement() {
            return --val;
        },
        reset() {
            return (val = init);
        },
    };
}


const counter = createCounter(5)
counter.increment();
counter.reset();
counter.decrement();
