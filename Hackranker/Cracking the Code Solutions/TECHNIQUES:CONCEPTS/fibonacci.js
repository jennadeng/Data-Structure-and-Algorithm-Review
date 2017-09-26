function processData(input) {
    var n = parseInt(input);
    console.log(fibonacciDP(n));
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});

// Recursion
function fibonacci(n) {
    if(n === 0){
        return 0;
    } else if(n === 1){
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Bottom up Dynamic programming solution
function fibonacciDP(n) {
    var dpTable = [];
    dpTable[0] = 0;
    dpTable[1] = 1;

    for(var i = 2; i <= n; i++){
        dpTable[i] = dpTable[i - 1] + dpTable[i - 2];
    }

    return dpTable[n];
}
