let data = [];

function setup() {
    createCanvas(displayWidth, displayHeight);
    colorMode(HSB, 360, 100, 100);
};

function draw() {
    background(0);
// stroke(30, 100, 100)

// let xalt = 0;
// let yalt = height;

//     for (let i = 0; i < data.length; i++) {
//         let d = data[i];
//         let x = map(i, 1, 100, 0, width);
//         let y = map(100, 0, 1000, height, 0);

//         fill(30, 100, 100)
//         circle(x, y, 5);
//             stroke(30, 100, 100);
//             line(xalt, yalt, x, y);

//             xalt = x;
//             yalt = y;
//     }
};


let ws = new WebSocket("ws://localhost:1880/ws/receive")

ws.onopen = function (event) {
    console.log(event);
};


ws.onmessage = function(msg){
    data.push(JSON.parse(msg.data));
    if (data.length > 10) {
        data.shift();
    }
    console.log(data);
};