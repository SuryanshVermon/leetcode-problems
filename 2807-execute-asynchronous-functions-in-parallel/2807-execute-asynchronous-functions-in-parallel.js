var promiseAll = async function(functions) {
    return await new Promise((resolve, reject) => {

        let arr = Array(functions.length);
        let waitingFor = functions.length;

        for(let i = 0; i < functions.length; ++i){
            functions[i]()
                .then((result) => { 
                    arr[i] = result; 
                    if (--waitingFor === 0) resolve(arr);
                }).catch(reject);
        }
    });
};
/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
