from console_gfx import ConsoleGfx

# Function definitions

# Method 1
def to_hex_string(data):
    """
    Convert a list of integers to a hexadecimal string
    :param data: a sequence of integers
    :return: a hexadecimal string
    """
    hex_string = ""
    for integer in data:
        if integer > 9:
            hex_digit = chr(ord("a") + integer - 10)
        else:
            hex_digit = str(integer)
        hex_string = hex_string + hex_digit
    return hex_string


# Method 2
def count_runs(flat_data):
    """
    Count the number of runs in a non-encoded image data set.
    The runs have a maximum length of 15 pixels.
    :param flat_data: a sequence of non-encoded image data
    :return: the number of runs in the image data
    """
    last_pixel = None
    runs = 0
    run_limit = 15
    for pixel in flat_data:
        if pixel != last_pixel or run_limit == 0:
            runs += 1
            run_limit = 15
        last_pixel = pixel
        run_limit -= 1
    return runs


# Method 3
def encode_rle(flat_data):
    """
    Perform run-length-encoding on an image data set.
    :param flat_data: a sequence of non-encoded image data
    :return: an encoded list of image data
    """
    rle_data = []
    last_pixel = None
    run_length = 1
    for pixel in flat_data:
        if pixel == last_pixel and run_length < 15:
            run_length += 1
            rle_data[-2] = run_length
        else:
            run_length = 1
            rle_data.append(run_length)
            rle_data.append(pixel)
        last_pixel = pixel
    return rle_data


# Method 4
def get_decoded_length(rle_data):
    """
    Return the decompressed length of an encoded image
    data set.
    :param rle_data: a sequence of an encoded image data set
    :return: the length of the sequence if it was decompressed
    """
    total_length = 0
    for i, run_length in enumerate(rle_data):
        if i % 2 == 0:
            total_length += run_length
    return total_length


# Method 5 - Decode RLE data and return expanded list
def decode_rle(rle_data):
    expanded_data = []
    for i, element in enumerate(rle_data):
        if i % 2 == 0:
            for run_length in range(0, element):
                expanded_data.append(rle_data[i + 1])
    return expanded_data


# Method 6 - Convert hexadecimal string to a list of integers
def string_to_data(data_string):
    int_list = []
    for i in range(0, len(data_string)):
        digit = data_string[i]
        if digit > "9":
            digit = digit.casefold()
            digit = 10 + ord(digit) - ord("a")
        else:
            digit = int(digit)
        int_list.append(digit)
    return int_list


# Method 7 - Reformat RLE data for readability
def to_rle_string(rle_data):
    rle_string = ""
    for i in range(0,len(rle_data),2):
        rle_string += f"{rle_data[i]}" + to_hex_string([rle_data[i + 1]])
        if i < (len(rle_data) - 2):
            rle_string += ":"
    return rle_string


# Method 8 - Convert readable RLE data to raw RLE data (reverse of Method 7)
def string_to_rle(rle_string):
    temp_data = rle_string.split(":")
    rle_data = []
    for element in temp_data:
        hex_char = element[-1].casefold()
        run_val = element[:-1]
        if hex_char.isalpha():
            hex_char = ord(hex_char) - ord("a") + 10
        rle_data.extend([int(run_val), int(hex_char)])
    return rle_data


if __name__ == '__main__':
    # Main program
    image_data = None

    # Welcome message
    print("Welcome to the RLE image encoder!\n")

    # Display the test rainbow
    print("Displaying Spectrum Image:")
    ConsoleGfx.display_image(ConsoleGfx.test_rainbow)
    print()

    # Run the program
    while True:

        # Print the menu
        print("\nRLE Menu\n"
              "--------\n"
              "0. Exit\n"
              "1. Load File\n"
              "2. Load Test Image\n"
              "3. Read RLE String\n"
              "4. Read RLE Hex String\n"
              "5. Read Data Hex String\n"
              "6. Display Image\n"
              "7. Display RLE String\n"
              "8. Display Hex RLE Data\n"
              "9. Display Hex Flat Data\n")

        # Prompt the user for menu option
        user_selection = int(input("Select a Menu Option: "))

        # Option 0 - Exit
        if user_selection == 0:
            break

        # Option 1 - Load File
        if user_selection == 1:
            file = input("Enter name of file to load: ")
            image_data = ConsoleGfx.load_file(file)

        # Option 2 - Load Test Image
        elif user_selection == 2:
            image_data = ConsoleGfx.test_image
            print("Test image data loaded.")

        # Option 3 - Read RLE String
        elif user_selection == 3:
            user_data = input("Enter an RLE string to be decoded: ")
            image_data = string_to_rle(user_data)
            image_data = decode_rle(image_data)

        # Option 4 - Read RLE Hex String
        elif user_selection == 4:
            user_data = input("Enter the hex string holding RLE data: ")
            image_data = string_to_data(user_data)
            image_data = decode_rle(image_data)

        # Option 5 - Read data Hex String
        elif user_selection == 5:
            user_data = input("Enter the hex string holding flat data: ")
            image_data = string_to_data(user_data)

        # Option 6 - Display Image
        elif user_selection == 6:
            print("Displaying image...")
            ConsoleGfx.display_image(image_data)

        # Option 7 - Display RLE String
        elif user_selection == 7:
            print(f"RLE representation: {to_rle_string(encode_rle(image_data))}")

        # Option 8 - Display Hex RLE Data
        elif user_selection == 8:
            print(f"RLE hex values: {to_hex_string(encode_rle(image_data))}")

        # Option 9 - Display Hex Flat Data
        elif user_selection == 9:
            print(f"Flat hex values: {to_hex_string(image_data)}")
