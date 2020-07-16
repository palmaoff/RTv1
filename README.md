# RTv1

RTv1 is simple ray tracing program, done as part of School21 course.

## Installation

Run `make` in the root of the repository for build a RTv1 file.

```
git clone https://github.com/palmaoff/RTv1.git
cd RTv1
make
```

## Usage

./RTv1 [filename] 

As parameter you put a file with scene config file, examples you can find in scene folder.

## Capabilities

As basic ray tracing program you can add in your scene 4 basic figures with some options of light management

Figures:

- Sphere
- Plane
- Cylinder
- Cone 

And options you can change:

//...\

## Hotkeys
- W A S D - <move camera Up/Left/Down/Right>
- Arrows Up/Down/Left/Right - <turn camera Up/Down/Left/Right>
- Top row +/- - <Zoom in/Zoom out>
- R - <redraw scene>
- Esc - <exit>

## Syntax requirements for scene
- !NO TABULATION between words (separated by spaces) - ONLY SPACES
- Add tags for \"scene\" (camera & lights) and \"objects\" (figures)
- Tag "scene" is the first, "objects" is second
- Add CURLY brackets for all text objects (e.g. camera, light, sphere)
- CURLY brackets \"scene\" and \"camera\": \"{\" & \"};\"
- CURLY brackets other: \"{\" & \"}\"
- Add USUAL brackets + spaces for all object's configurations
- Positive values for all objects configurations except pos and dir
- New line \"\\n\" after curly brackets, tags and config
- For example, use prepared scenes

## Text objects description
- **`scene`** \
  **`camera`** !(only one)\
 `pos` (vec_int_3) ( x x x ) - camera position\
 `dir` (vec_int_3) ( x x x ) - camera direction\
  **`light`**\
 `type` ( string ) - type of light (Directional, Point, Ambient)\
 `pos` (except Ambient)(vec_int_3) ( x x x) - light position")\
 `intensity` (positive float) ( x.x ) - light intensity\
 `dir` (! only for Directional)(vec_int_3) ( x x x ) - light direction
- **`objects`**\
  **`all objects`**\
 `specular`(int)(optional) ( x ) - reflection (if not specified - 0)\
  **`sphere`**\
 `pos` (vec_int_3) ( x x x ) - sphere position\
 `color_rgb` (vec_hex_3) ( 0x00 0x00 0x00 )- color of sphere\
 `size` (int) ( x ) - size of sphere\
  **`cone`**\
 `pos` (vec_int_3) ( x x x ) - cone position\
 `dir` (vec_int_3) ( x x x ) - cone direction\
 `color_rgb` (vec_hex_3) ( 0x00 0x00 0x00 ) - color of cone\
 `angle` (float) ( x.x ) - angle of cone\
  **`plane`**\
 `pos` (vec_int_3) ( x x x ) - plane position\
 `dir` (vec_int_3)( x x x ) - plane direction\
 `color_rgb` (vec_hex_3) ( 0x00 0x00 0x00 ) - color of plane\
  **`cylinder`**\
 `pos` (vec_int_3) ( x x x ) - cylinder position\
 `dir` (vec_int_3)( x x x ) - cylinder direction\
 `color_rgb` (vec_hex_3) ( 0x00 0x00 0x00 ) - color of cylinder\
 `size` (int)( x ) - size of cylinder
