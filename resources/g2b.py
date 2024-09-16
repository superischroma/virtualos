from PIL import Image

pixels = []

with Image.open("glyphs.png") as image:
    data = image.getdata()
    for x in data:
        if x[0] == 255:
            pixels.append(1)
        else:
            pixels.append(0)

def read_glyph(index):
    ps = []
    for y in range(16):
        for x in range(8):
            ps.append(pixels[((index * 8) + index + x) + ((288 * ((16 * (index // 32)))) + (y * 288))])
    return ps

res = read_glyph(65 + 32)
for i, r in enumerate(res):
    if i % 8 == 0 and i != 0:
        print()
    if r == 1:
        print(f"□ ", end="")
    else:
        print("  ", end="")