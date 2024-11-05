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

class sound:
    ANY: int                # Value: -2
    DEFAULT: int            # Value: -1
    WAVEFORM_SINE: int      # Value: 1
    WAVEFORM_SAWTOOTH: int  # Value: 3
    WAVEFORM_SQUARE: int    # Value: 2
    WAVEFORM_TRIANGLE: int  # Value: 1

    def beep(freq: int = 440, duration: int = 500, volume: int = 100, *, attack: int = 0, decay: int = 0, sustain: int = 100, release: int = 0, transition: int = 10, waveform: int = WAVEFORM_SINE, channel: int = DEFAULT) -> None:
        """Plays a beep sound from the hub"""
    
    def stop() -> None:
        """Stops all noise from the hub"""
    
    def volume(volume: int) -> None:
        """"""

class button:
    def pressed(button: int) -> int:
        """This module allows you to react to buttons being pressed on the hub. You must first import the button module to use the buttons."""

    LEFT: int   # Value: 1
    RIGHT: int  # Value: 2