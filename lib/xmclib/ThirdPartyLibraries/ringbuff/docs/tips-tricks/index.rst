Tips & tricks
=============

Application buffer size
^^^^^^^^^^^^^^^^^^^^^^^

Buffer size shall always be ``1`` byte bigger than anticipated data size.

When application uses buffer for some data block `N` times, it is advised to set buffer size to `1` byte more than `N * block_size` is.
This is due to `R` and `W` pointers alignment.

.. note:: 
    For more information, check :ref:`How it works`.

.. code-block:: c

    /* Number of data blocks to write */
    #define N          3

    /* Create custom data structure */
    /* Data is array of 2 32-bit words, 8-bytes */
    uint32_t d[2];

    /* Create buffer structures */
    ringbuff_t buff_1;
    ringbuff_t buff_2;

    /* Create data for buffers. Use sizeof structure, multiplied by N (for N instances) */
    /* Buffer with + 1 bytes bigger memory */
    uint8_t buff_data_1[sizeof(d) * N + 1];
    /* Buffer without + 1 at the end */
    uint8_t buff_data_2[sizeof(d) * N];

    /* Write result values */
    size_t len_1;
    size_t len_2;

    /* Initialize buffers */
    ringbuff_init(&buff_1, buff_data_1, sizeof(buff_data_1));
    ringbuff_init(&buff_2, buff_data_2, sizeof(buff_data_2));

    /* Write data to buffer */
    for (size_t i = 0; i < N; ++i) {
        /* Prepare data */
        d.a = i;
        d.b = i * 2;

        /* Write data to both buffers, memory copy from d to buffer */
        len_1 = ringbuff_write(&buff_1, d, sizeof(d));
        len_2 = ringbuff_write(&buff_2, d, sizeof(d));

        /* Print results */
        printf("Write buffer 1: %d/%d bytes; buffer 2: %d/%d\r\n",
            (int)len_1, (int)sizeof(d),
            (int)len_2, (int)sizeof(d));
    }

When the code is executed, it procudes following output::

    Write: buffer 1: 8/8; buffer 2: 8/8
    Write: buffer 1: 8/8; buffer 2: 8/8
    Write: buffer 1: 8/8; buffer 2: 7/8 <-- See here -->

.. toctree::
    :maxdepth: 2