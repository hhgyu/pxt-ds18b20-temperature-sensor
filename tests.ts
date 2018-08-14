// tests go here; this will not be compiled when this package is used as a library

ds18b20.init(Pins.P0)
basic.forever(() => {
    basic.showNumber(ds18b20.get_temp())
    basic.pause(500)
})
