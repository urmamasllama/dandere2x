#include <chrono>
#include "Driver.h" //driver_difference
#include "Plugins/Fade/Fade.h"
#include "Image/DebugImage/DebugImage.h"

/**
 * Todo
 * - Implement CLI interface into dandere2x python for long -term usability.
 * - Debug function for people to test individual features.
 */



void benchmark(){
    #include "Image/Image.h"
    #include "Plugins/PFrame/PFrame.h"

    string im1_file =
            "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\inputs\\frame42.jpg";

    string im2_file =
            "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\inputs\\frame43.jpg";

    string im2_file_compressed =
            "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\compressed\\43.jpg";

    auto start = std::chrono::high_resolution_clock::now();
    for(int x = 0; x < 1; x++) {


        int block_size = 30;
        int step_size = 4;

        shared_ptr<Image> im1 = make_shared<Image>(im1_file);
        shared_ptr<Image> im2 = make_shared<Image>(im2_file);
        shared_ptr<Image> im2_copy = make_shared<Image>(im2_file); //for corrections
        shared_ptr<Image> im2_compressed = make_shared<Image>(im2_file_compressed);

        //File locations that will be produced
        string p_data_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\pdata.txt";

        string inversion_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\idata.txt";

        string correction_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\cdata.txt";

        string fade_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\fdata.txt";

        /** Run dandere2xCpp Plugins (this is where all the computation of d2xcpp happens) */


        Fade fade = Fade(im1, im2, im2_compressed, block_size, fade_file);
        fade.run();

        PFrame pframe = PFrame(im1, im2, im2_compressed, block_size, p_data_file, inversion_file, step_size);
        pframe.run();

        Correction correction = Correction(im2, im2_copy, im2_compressed, correctionBlockSize, correction_file, 2);
        correction.run();

        //For Debugging. Create a folder called 'debug_frames' in workspace when testing this
        DebugImage before = DebugImage::create_debug_from_image(*im2);
        before.save("C:\\Users\\windwoz\\Desktop\\pythonreleases\\0.7.3\\demo_folder\\violethigher\\30.png");

        /** Save the files generated by our plugins here */
        std::cout << "30" << std::endl;
        std::cout << ImageUtils::mse_image(*im2, *im2_copy) << std::endl;
        pframe.print_stats();
    }

    auto stop = std::chrono::high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    cout << "Time taken by function 1:  "
         << duration.count() << " seconds" << endl;

    for(int x = 0; x < 1; x++) {

        int block_size = 60;
        int step_size = 4;

        shared_ptr<Image> im1 = make_shared<Image>(im1_file);
        shared_ptr<Image> im2 = make_shared<Image>(im2_file);
        shared_ptr<Image> im2_copy = make_shared<Image>(im2_file); //for corrections
        shared_ptr<Image> im2_compressed = make_shared<Image>(im2_file_compressed);

        //File locations that will be produced
        string p_data_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\pdata.txt";

        string inversion_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\idata.txt";

        string correction_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\cdata.txt";

        string fade_file =
                "C:\\Users\\windwoz\\Desktop\\workspace\\yn_fade_perve\\debug_info\\fdata.txt";

        /** Run dandere2xCpp Plugins (this is where all the computation of d2xcpp happens) */


        Fade fade = Fade(im1, im2, im2_compressed, block_size, fade_file);
        fade.run();

        PFrame pframe = PFrame(im1, im2, im2_compressed, block_size, p_data_file, inversion_file, step_size);
        pframe.run();

        Correction correction = Correction(im2, im2_copy, im2_compressed, correctionBlockSize, correction_file, 2);
        correction.run();

        //For Debugging. Create a folder called 'debug_frames' in workspace when testing this
        DebugImage before = DebugImage::create_debug_from_image(*im2);
        before.save("C:\\Users\\windwoz\\Desktop\\pythonreleases\\0.7.3\\demo_folder\\violethigher\\60.png");

        /** Save the files generated by our plugins here */

        std::cout << "60" << std::endl;
        std::cout << ImageUtils::mse_image(*im2, *im2_copy) << std::endl;

        pframe.print_stats();
    }

    stop = std::chrono::high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    cout << "Time taken by function: 2"
         << duration.count() << " seconds" << endl;


}

int main(int argc, char **argv) {
    benchmark();
//
//    bool debug = false; //debug flag
//
//    string workspace = "C:\\Users\\windwoz\\Desktop\\workspace\\violetfade\\";
//    int frame_count = 120;
//    int block_size = 30;
//    int step_size = 4;
//    string run_type = "n";// 'n' or 'r'
//    int resume_frame = 71;
//    string extension_type = ".jpg";
//
//    cout << "Hello Dandere!!" << endl;
//
//
//    //load arguments
//    if (!debug) {
//        workspace = argv[1];
//        frame_count = atoi(argv[2]);
//        block_size = atoi(argv[3]);
//        step_size = atoi(argv[4]);
//        run_type = argv[5];
//        resume_frame = atoi(argv[6]);
//        extension_type = argv[7];
//    }
//
//    cout << "Settings" << endl;
//    cout << "workspace: " << workspace << endl;
//    cout << "frame_count: " << frame_count << endl;
//    cout << "block_size: " << block_size << endl;
//    cout << "step_size: " << step_size << endl;
//    cout << "run_type: " << run_type << endl;
//    cout << "ResumeFrame (if valid): " << resume_frame << endl;
//    cout << "extension_type: " << extension_type << endl;
//
//    if (run_type == "n")
//        driver_difference(workspace, 1, frame_count, block_size, step_size, extension_type);
//    else if (run_type == "r")
//        driver_difference(workspace, resume_frame, frame_count, block_size, step_size, extension_type);

    return 0;
}
