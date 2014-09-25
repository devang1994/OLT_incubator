
# OpenLabTools Incubator

## Introduction
The incubator project aims to make a cost-effective open-source customizable incubator from of the shelf components for use primarily in biology research

The project has been designed to be fully compatible with OpenLabTools Web interface to provide ease of control and access. Because of the web based interface the incubator can also be controlled and monitored remotely.

## Temperature Control

Peltier modules have been used as the basic heat transfer component for the incubator.
Peltier modules act as solid state heat pumps allowing us to either cool or heat the module by simply switching the current going into the module.

An off the shelf CPU heatsink with fan has been attached to both the sides of the peltier modules to effectively dissipate heat to either the surroundings or the incubation chamber.

## Electronics

A simple [H-Bridge](http://en.wikipedia.org/wiki/H_bridge) circuit was designed and made using off the shelf relays and darlington transistors. The H-Bridge is controlled by the micro-controller which allows current to pass in either direction across the peltier module allowing us to either heat or cool the system.

A DHT 22 sensor is used to detect the temperature in the box to do appropriate control.

## Microprocessor

Arduino UNO has been used as the micro-controller for this application, it can be controlled by sending the required temperature to it via the serial protocol, it also reads the temperature in the incubator and returns it via the serial protocol.

The code has been written using the Arduino IDE.

## Incubator chamber

The current  incubator chamber has been made using a 2mm acrylic sheet, this can be changed to suit particular needs of the application.

The acrylic sheet sheet has been milled using the [Shapeoko 2](http://docs.shapeoko.com/) Desktop CNC milling machine to make the required holes for fitting in the peltier modules and associated heatsinks as shown in the image below.

Image here

The individual acrylic sheets are held together using angled holding brackets which were 3d printed using the MakerBot Replicator 3d printer

Image here

## Development Notes

To do:

1. Replace relays with power MOSFETs
2. Use PWM to do PID control of the temperature
3. Redesign Holding Brackets to have even smaller air gaps at joints or explore possibility of using acrylic cement or another similar product





