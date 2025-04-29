{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "provenance": [],
      "authorship_tag": "ABX9TyMqNLS36IyC71gFVRq3t8R/",
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/poorvautturkar25/DAA/blob/main/qsort.c\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "id": "tKHnrHMMaL-M"
      },
      "outputs": [],
      "source": [
        "#include<stdio.h>\n",
        "void Qsort(int n[], int low, int high )\n",
        "{\n",
        " int j = low , k=high, i, pivot, tmp;\n",
        "i = (j + k)/2;\n",
        " pivot = n[i];\n",
        "\n",
        "do\n",
        "{\n",
        " while (n[j] < pivot && j<= high) j++;\n",
        " while(n[k] > pivot && k >= low )k--;\n",
        " if ( j <= k)\n",
        "{\n",
        "  tmp = n[j];\n",
        "  n[j] = n[k];\n",
        "  n[k] = tmp;\n",
        "  j++;\n",
        "  k--;\n",
        "}\n",
        "} while ( j <= k );\n",
        " if ( j <= high )\n",
        "  Qsort (n,j, high);\n",
        " if ( k >= 100 )\n",
        " Qsort (n, low,k);\n",
        "}\n",
        "int main()\n",
        "{\n",
        " int n;\n",
        "\n",
        " printf(\"enter the number of element =\");\n",
        "  scanf(\"%d\", &n);\n",
        "\n",
        "int arr[n];\n",
        " printf(\"enter %d element =\",n);\n",
        "  for (int i=0;i<n;i++)\n",
        "  scanf(\"%d\",&arr[i]);\n",
        "\n",
        "  Qsort(arr,0,n-1);\n",
        "   printf(\"sorted array= \");\n",
        "  for (int i=0;i<n;i++)\n",
        "  printf(\"%d \",arr[i]);\n",
        "\n",
        "  return 0;\n",
        "}\n"
      ]
    }
  ]
}