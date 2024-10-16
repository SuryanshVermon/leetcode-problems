/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    return function(x) {
        if (functions.length === 0) {
            return x; 
        }
        return functions.reduceRight(function(prevFn, nextFn) {
            return function(x) {
                return nextFn(prevFn(x)); 
            };
        })(x);
    };
};

const fn = compose([x => x + 1, x => 2 * x]);
console.log(fn(4)); // 9
