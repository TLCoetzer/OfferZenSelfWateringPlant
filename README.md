# OfferZenSelfWateringPlant
Basic implementation for OfferZen Self Watering Plant builder event

The main file is in the SelfWateringPlant folder.
It's the basic implimentation from the event evening.

It reads the sensor values, then if greater than 400 it turns the pump on for 2 seconds, then off again for 10 seconds to give the water chance to absorb.
It then reads again. If the water is reading is <= 400 then it just blinks the light on for 2 seconds and the off for 2 seconds before taking another reading.
It just keeps looping like this forever.

It's a very basic algorythm and it works :)

Well, it works for a short while but then the conductivity of the water seems to lower and the sensor reading stays above 400 even with the pplant flooding, so I may have to simply increase the threshold to something like 500 or improve the algorythm to only start checking moisture levels again once it reaches say 600 or something.






