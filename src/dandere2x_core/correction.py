#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Name: Dandere2X Merge
Author: CardinalPanda
Date Created: March 22, 2019
Last Modified: April 2, 2019
"""
import logging

from dandere2x_core.dandere2x_utils import get_list_from_file
from wrappers.frame import DisplacementVector
from wrappers.frame import Frame


# correction size needs to be added to config file

def correct_image(context, block_size, frame_base: Frame, list_correction: list):
    logger = logging.getLogger(__name__)

    # load context
    scale_factor = context.scale_factor

    predictive_vectors = []
    out_image = Frame()
    out_image.create_new(frame_base.width, frame_base.height)
    out_image.copy_image(frame_base)
    scale_factor = int(scale_factor)

    for x in range(int(len(list_correction) / 4)):  # / 4 because each there's 4 data points per block
        predictive_vectors.append(DisplacementVector(int(list_correction[x * 4 + 0]),
                                                     int(list_correction[x * 4 + 1]),
                                                     int(list_correction[x * 4 + 2]),
                                                     int(list_correction[x * 4 + 3])))
    # copy over predictive vectors into new image
    for vector in predictive_vectors:
        out_image.copy_block(frame_base, block_size * scale_factor,
                             vector.x_2 * scale_factor,
                             vector.y_2 * scale_factor,
                             vector.x_1 * scale_factor,
                             vector.y_1 * scale_factor)

    return out_image


def main():
    block_size = 4
    scale_factor = 2

    frame_base = Frame()
    frame_base.load_from_string("C:\\Users\\windwoz\\Desktop\\image_research\\shelter\\merged2x.jpg")
    list_predictive = get_list_from_file("C:\\Users\\windwoz\\Desktop\\image_research\\shelter\\correction.txt")
    out_location = ("C:\\Users\\windwoz\\Desktop\\image_research\\shelter\\new_correction.jpg")

    correct_image(block_size, scale_factor, frame_base, list_predictive, out_location)


if __name__ == "__main__":
    main()
