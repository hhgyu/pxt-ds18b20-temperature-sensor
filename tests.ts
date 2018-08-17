// tests go here; this will not be compiled when this package is used as a library

ds18b20.init(Pins.P0)

let i = 0;
basic.forever(() => {
    if(i > 10) {
        //ds18b20.deinit(Pins.P0)
    }

    basic.showNumber(ds18b20.get_temp(Pins.P0))
    basic.pause(500)
    i++;
})
