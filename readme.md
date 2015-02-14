# [Sanitarium HD Patcher v0.2.1](http://makegames.co.uk/sanitariumhd/)
A little runtime, in-memory patcher to allow Sanitarium to run at a resolution
of your chosing! As the patch is applied in memory it will **not** modify your
files.

# Changelog
* v0.2.1
	* Changed to statically linking runtime, to avoid dependency
* v0.2.0
	* Added support for current GOG build
	* Added support for another disc version

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

### Supported/tested game versions (by MD5, modified DD/MM/YYYY)
* `0A09F1956FCA274172B0BB90AA5F08A7` - modified 08/05/2000
* `5B173E752B2629240CDCF16221DC1164` - Disc version, modified 16/04/1998
* `3CB90D988460FC0AD095956D8415FD36` - GOG version, modified  10/11/2009

## Known issues
* Surface is not cleared between frames. This will result in a ghosting effect
where previous frames drawn outside the original 640x480 viewport will remain

Enjoy!
by [Schtee](http://www.twitter.com/schtee) |
[MakeGames.co.uk](http://www.makegames.co.uk)
