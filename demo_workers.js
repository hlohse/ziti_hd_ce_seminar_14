var i = 0;

//this.onmessage = function(event) {
//    postMessage("Pong!");
//}

this.addEventListener('message', function (e) {
    postMessage();
}, false);

function init() {
    postMessage("Pong!");
}

init();

