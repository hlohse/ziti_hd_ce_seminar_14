function getArray(bytes) {
    var array  = new ArrayBuffer(bytes);
    var viewU8 = new Uint8Array(array);
    return viewU8;
}

function timeMs() {
    return performance.now() * 1000;
}

