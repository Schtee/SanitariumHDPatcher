# Sanitarium HD Patcher v0.1.0
A little runtime, in-memory patcher to allow Sanitarium to run at a resolution
of your chosing! As the patch is applied in memory it will **not** modify your
files.

<iframe width="560" height="315" src="https://www.youtube.com/embed/LIX9yfyEX50" frameborder="0" allowfullscreen></iframe>

## Usage
### Simple
1. Extract `Sanitarium HD Patcher.exe` and `patches.json` to your Sanitarium
game folder
2. Create a shortcut to `Sanitarium HD Patcher.exe`
3. Right click the shortcut -> Properties
4. Add to the end of `Target`
	* `-x [resolution width]`
	* `-y [resolution height]`
	* `-- [command line arguments to pass to Sanitarium]`
	* e.g.: `Sanitarium.exe -x 1920 -y 1080 -- -w -e /skip`, for a 1080p game,
	windowed, with DirectDraw emulation enabled (recommended)

### Advanced
The patcher can be run from outside the game directory by providing the
following command line argument:
* `-e [game executable location]`, e.g. `-e c:\Games\Sanitarium\Sntrm.exe`
This can also be useful if your game executable is not named `Sntrm.exe`

## Known issues
* Surface is not cleared between frames. This will result in a ghosting effect
where previous frames drawn outside the original 640x480 viewport will remain

Enjoy!
by [Schtee](http://www.twitter.com/schtee) |
[MakeGames.co.uk](http://www.makegames.co.uk)
