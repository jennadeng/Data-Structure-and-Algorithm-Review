process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;
var util = require('util');

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////
var wordMap = {};

function main() {
    var n = parseInt(readLine());
    for(var a0 = 0; a0 < n; a0++){
        var op_temp = readLine().split(' ');
        var op = op_temp[0];
        var contact = op_temp[1];

        if(op == "add"){
            //console.log("add this" + contact);
            addWord(contact);
        }else if(op == "find"){
            console.log(findWord(contact));
        }
    }
}


function addWord(word){
    for( l = 0; l < word.length; l ++ ){
        //console.log("letter " + word.substring(0, l + 1 ));
        if( word.substring(0, l + 1) in wordMap ){
            wordMap[word.substring(0, l + 1)]++;
        }else{
            wordMap[word.substring(0, l + 1)] = 1;
        }
    }
}

function findWord(word){
    return (typeof wordMap[word] === "undefined")? 0 : wordMap[word];
}
