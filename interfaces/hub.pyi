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

class light:
    def color(light: int, color: int) -> None:
        """Change the color of a light on the hub."""

    POWER: int      # Value: 0
    CONNECT: int    # Value: 1

class motion_sensor:
    def acceleration(raw_unfiltered: bool = False) -> None:
        """Returns a tuple containing x, y & z acceleration values as integers. The values are in mg (0.001 g)"""

    def tilt_angles() -> tuple[int, int, int]:
        """Returns a tuple containing yaw pitch and roll values as integers. Values are decidegrees"""

class light_matrix:
    def clear() -> None:
        """Switches off all of the pixels on the Light Matrix."""
    
    def get_orientation() -> int:
        """Retrieve the current orientation of the Light Matrix."""

    def get_pixel(x: int, y: int) -> int:
        """Retrieve the intensity of a specific pixel on the Light Matrix."""

    def set_orientation(top: int) -> int:
        """Change the orientation of the Light Matrix. All subsequent calls will use the new orientation."""

    def set_pixel(x: int, y: int, intensity: int) -> None:
        """Sets the brightness of one pixel (one of the 25 LEDs) on the Light Matrix."""

    def show(pixels: list[int]) -> None:
        """Change all the lights at the same time."""

    def show_image(image: int) -> None:
        """Display one of the built in images on the display."""

    def write(text: str, intensity: int = 100, time_per_character: int = 500) -> None:
        """Displays text on the Light Matrix, one letter at a time, scrolling from right to left except if there is a single character to show which will not scroll"""

    IMAGE_HEART: int             # Value: 1
    IMAGE_HEART_SMALL: int       # Value: 2
    IMAGE_HAPPY: int             # Value: 3
    IMAGE_SMILE: int             # Value: 4
    IMAGE_SAD: int               # Value: 5
    IMAGE_CONFUSED: int          # Value: 6
    IMAGE_ANGRY: int             # Value: 7
    IMAGE_ASLEEP: int            # Value: 8
    IMAGE_SURPRISED: int         # Value: 9
    IMAGE_SILLY: int             # Value: 10
    IMAGE_FABULOUS: int          # Value: 11
    IMAGE_MEH: int               # Value: 12
    IMAGE_YES: int               # Value: 13
    IMAGE_NO: int                # Value: 14
    IMAGE_CLOCK12: int           # Value: 15
    IMAGE_CLOCK1: int            # Value: 16
    IMAGE_CLOCK2: int            # Value: 17
    IMAGE_CLOCK3: int            # Value: 18
    IMAGE_CLOCK4: int            # Value: 19
    IMAGE_CLOCK5: int            # Value: 20
    IMAGE_CLOCK6: int            # Value: 21
    IMAGE_CLOCK7: int            # Value: 22
    IMAGE_CLOCK8: int            # Value: 23
    IMAGE_CLOCK9: int            # Value: 24
    IMAGE_CLOCK10: int           # Value: 25
    IMAGE_CLOCK11: int           # Value: 26
    IMAGE_ARROW_N: int           # Value: 27
    IMAGE_ARROW_NE: int          # Value: 28
    IMAGE_ARROW_E: int           # Value: 29
    IMAGE_ARROW_SE: int          # Value: 30
    IMAGE_ARROW_S: int           # Value: 31
    IMAGE_ARROW_SW: int          # Value: 32
    IMAGE_ARROW_W: int           # Value: 33
    IMAGE_ARROW_NW: int          # Value: 34
    IMAGE_GO_RIGHT: int          # Value: 35
    IMAGE_GO_LEFT: int           # Value: 36
    IMAGE_GO_UP: int             # Value: 37
    IMAGE_GO_DOWN: int           # Value: 38
    IMAGE_TRIANGLE: int          # Value: 39
    IMAGE_TRIANGLE_LEFT: int     # Value: 40
    IMAGE_CHESSBOARD: int        # Value: 41
    IMAGE_DIAMOND: int           # Value: 42
    IMAGE_DIAMOND_SMALL: int     # Value: 43
    IMAGE_SQUARE: int            # Value: 44
    IMAGE_SQUARE_SMALL: int      # Value: 45
    IMAGE_RABBIT: int            # Value: 46
    IMAGE_COW: int               # Value: 47
    IMAGE_MUSIC_CROTCHET: int    # Value: 48
    IMAGE_MUSIC_QUAVER: int      # Value: 49
    IMAGE_MUSIC_QUAVERS: int     # Value: 50
    IMAGE_PITCHFORK: int         # Value: 51
    IMAGE_XMAS: int              # Value: 52
    IMAGE_PACMAN: int            # Value: 53
    IMAGE_TARGET: int            # Value: 54
    IMAGE_TSHIRT: int            # Value: 55
    IMAGE_ROLLERSKATE: int       # Value: 56
    IMAGE_DUCK: int              # Value: 57
    IMAGE_HOUSE: int             # Value: 58
    IMAGE_TORTOISE: int          # Value: 59
    IMAGE_BUTTERFLY: int         # Value: 60
    IMAGE_STICKFIGURE: int       # Value: 61
    IMAGE_GHOST: int             # Value: 62
    IMAGE_SWORD: int             # Value: 63
    IMAGE_GIRAFFE: int           # Value: 64
    IMAGE_SKULL: int             # Value: 65
    IMAGE_UMBRELLA: int          # Value: 66
    IMAGE_SNAKE: int             # Value: 67

