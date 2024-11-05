def device_uuid() -> str:
    """Retrieve the device id."""

def hardware_id() -> str:
    """Retrieve the hardware id."""

def power_off() -> int:
    """Turns off the hub."""

def temperature() -> int:
    """Retrieve the hub temperature. Measured in decidegrees celsius (d°C) which is 1 / 10 of a degree celsius (°C)"""

class port:
    """This module contains constants that enables easy access to the ports on the SPIKE Prime hub. Use the constants in all functions that takes a port parameter."""

    A: int  # Value: 0
    B: int  # Value: 1
    C: int  # Value: 2
    D: int  # Value: 3
    E: int  # Value: 4
    F: int  # Value: 5