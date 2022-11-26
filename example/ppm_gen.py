def main():
    f = open("test.ppm", "wb")

    f.write(b'P6\n')
    f.write(b'500 500\n')
    f.write(b'255\n')
    for i in range(500):
        for j in range(500):
            b = bytearray([i % 256, j % 256, 0])
            f.write(b)

    f.close()


if __name__ == "__main__":
    main()
