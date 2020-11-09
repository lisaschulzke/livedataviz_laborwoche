let ws = new WebSocket("ws://localhost:1880/ws/receive")

ws.onopen = function (event) {
    console.log(event);
};


ws.onmessage = function(msg){
    console.log(msg);
};