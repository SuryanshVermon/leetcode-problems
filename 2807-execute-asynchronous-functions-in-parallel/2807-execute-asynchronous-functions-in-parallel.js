/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    let cnt = 0;
    const ans = [];
    return new Promise((resolve, reject) => {
        functions.forEach((fn, index) => {
            fn()
            .then(res => {
                cnt += 1
                ans[index] = res
                if (cnt == functions.length) resolve(ans);
            })
            .catch(err => {
                reject(err)
            })
        })
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
