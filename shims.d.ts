// Auto-generated. Do not edit.


    /**
     * hhgyu
     * 2018-08-14
     * https://github.com/hhgyu/pxt-ds18b20-temperature-sensor
     *
     * Development environment specifics:
     * Written in Microsoft PXT
     * Tested with a pxt-ds18b20-temperature-sensor for micro:bit
     *
     * This code is released under the [MIT License](http://opensource.org/licenses/MIT).
     * Please review the LICENSE.md file included with this example. If you have any questions 
     * or concerns with licensing, please contact hhgyu15@gmail.com.
     * Distributed as-is; no warranty is given.
     */

declare namespace ds18b20 {
    /**
     * initialises local variablesssss
     */
    //% blockId=probe_init
    //% block="connect temperature probe to %pin" shim=DS18B20::init
    function init(pin: Pins): void;

    /**
     * get temperature to 1 decimal place
     */
    //% blockId = get_temp
    //% block="temperature" shim=DS18B20::get_temp
    function get_temp(): number;
}

// Auto-generated. Do not edit. Really.
