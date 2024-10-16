/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    var filteredArr = []; // Removed void
    for (var i = 0; i < arr.length; i++) { // Fixed the for loop parentheses
        if (fn(arr[i], i)) {
            filteredArr.push(arr[i]);
        }
    }
    return filteredArr; // Added semicolon
};
