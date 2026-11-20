<div align="center">

# 🛸 Space Shooter

### An Arduino Nano arcade game for your workbench

![Arduino Nano](https://img.shields.io/badge/Arduino-Nano%20ATmega328P-00878F?style=for-the-badge&logo=arduino&logoColor=white)
![PlatformIO](https://img.shields.io/badge/PlatformIO-Project-F5822A?style=for-the-badge&logo=platformio&logoColor=white)
![Display](https://img.shields.io/badge/Display-SH1106%20128%C3%9764-111827?style=for-the-badge)

**Pilot your ship through a scrolling starfield — built with buttons, pixels, and a little bit of C++.**

</div>

---

`SPACE SHOOTER` is a compact, hardware-based game for an **Arduino Nano**. A 128×64 OLED renders the starfield and player ship, while a TM1637 display is ready to show the score.

> [!NOTE]
> The current build includes the start animation and horizontal player movement. Bullets, enemies, collisions, and scoring are the next mission stages.

## ✨ Features

| Status | Feature |
| :---: | --- |
| ✅ | Animated scrolling-star start screen |
| ✅ | Pixel-art spaceship controlled by physical buttons |
| ✅ | Screen-edge movement limits |
| ✅ | TM1637 score display initialized at `0000` |
| 🛠️ | Bullet pool ready to connect to the game loop |
| 🚀 | UFOs, collisions, and scoring planned |

## 🧰 Hardware overview

The project brings together a compact set of arcade components:

- **Arduino Nano** — runs the game logic
- **128×64 I²C OLED** — displays the starfield, ship, and future enemies
- **TM1637 four-digit display** — reserved for the score
- **Three push buttons** — start the game and steer the ship

> [!TIP]
> A complete wiring diagram and pin reference will be added as the hardware build is finalized.

## 🎮 Controls

| Control | Action |
| --- | --- |
| **Start** | Launch the game from the intro screen |
| **Left** | Move the spaceship left |
| **Right** | Move the spaceship right |

1. Turn on the board and enjoy the scrolling starfield.
2. Press **START** to launch.
3. Steer the spaceship along the bottom of the OLED with **LEFT** and **RIGHT**.

## ⚡ Quick start

This repository is a [PlatformIO](https://platformio.org/) project. Its required libraries are declared in `platformio.ini` and are installed automatically by PlatformIO.

```bash
# Build for Arduino Nano (ATmega328P)
pio run

# Upload to the connected board
pio run --target upload

# Watch 9600-baud debug output
pio device monitor --baud 9600
```

If PlatformIO cannot find your board, supply the correct serial port:

```bash
pio run --target upload --upload-port COM3
```

Replace `COM3` with your board's port.

## 🗂️ Project map

```text
space-shooter/
├── include/             # Pin definitions and module interfaces
├── src/
│   ├── main.cpp         # Game state and main loop
│   ├── Display.cpp      # OLED and score-display setup
│   ├── Input.cpp        # Button setup and reads
│   ├── Spaceship.cpp    # Starfield, ship graphics, and movement
│   └── Bullet.cpp       # Reusable ten-bullet pool
└── platformio.ini       # Nano target and library dependencies
```

## 🛣️ Flight plan

- [x] Start-screen animation
- [x] Player movement
- [x] Score-display initialization
- [ ] Add a wiring diagram and pin reference
- [ ] Fire bullets from the start/fire button
- [ ] Draw and update active bullets
- [ ] Add UFO enemies
- [ ] Detect collisions
- [ ] Award and display score

## 📚 Libraries

- [U8g2](https://github.com/olikraus/u8g2) — SH1106 OLED graphics
- [TM1637Display](https://github.com/avishorp/TM1637) — four-digit score display

<div align="center">

**Built for tiny screens and big arcade energy. ✨**

</div>
