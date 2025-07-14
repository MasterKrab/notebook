# Notebook Competitive Programming Masterkrab

## Rules for ICPC notebooks

According to the official rules:

> This document may contain up to 25 pages of reference materials, single-sided, letter or A4 size, with pages numbered in the upper right-hand corner and your university name and team name printed in the upper left-hand corner. Text and illustrations must be readable by a person with correctable eyesight without magnification from a distance of 1/2 meter. It may include hand-written comments and corrections on the fronts of pages only. The document must be in some type of notebook or folder with the name of your institution on the front.

This means that:

Using A4 paper (which has a larger area than Letter), with Courier New 6pt (legible from 50cm) and 0.25in margins, we can fit 103 lines of 155 characters each per page (one sheet per page is allowed).

That is, approximately 200 lines of 75 characters per page. With 25 pages (the cover is not included since it goes on the folder), this totals 5,000 lines of up to 75 characters each.

# Installation on Arch Linux

Install Typst:

```sh
sudo pacman -S typst
```

Then, give execute permissions to the Typst binary:

```sh
chmod +x .typst/typst-linux
```

# Compile

To compile the document, run:

```sh
python make.py
```

# Notes

- Font size is calibrated to fit 60 characters per line just right.
