Ringbuffer documentation!
=========================

.. image:: static/images/logo.svg
	:align: center

.. class::center

:ref:`Download library` · `Github <https://github.com/MaJerle/ringbuff>`_

Features
^^^^^^^^

- Written in ANSI C99, compatible with size_t for size data types
- Platform independent, no architecture specific code
- FIFO (First In First Out) buffer implementation
- No dynamic memory allocation, data is static array
- Uses optimized memory copy instead of loops to read/write data from/to memory
- Thread safe when used as pipe with single write and single read entries
- Interrupt safe when used as pipe with single write and single read entries
- Suitable for DMA transfers from and to memory with zero-copy overhead between buffer and application memory
- Supports data peek, skip for read and advance for write
- User friendly MIT license

Requirements
^^^^^^^^^^^^

- C compiler

Example code
^^^^^^^^^^^^

Minimalistic example code to read and write data to buffer

.. code-block:: c

    /* Buffer variables */
    ringbuff_t buff;                            /* Declare ring buffer structure */
    uint8_t buff_data[8];                       /* Declare raw buffer data array */

    /* Application variables */
    uint8_t data[2];                            /* Application working data */
    size_t len;

    /* Application code ... */
    ringbuff_init(&buff, buff_data, sizeof(buff_data)); /* Initialize buffer */

    /* Write 4 bytes of data */
    ringbuff_write(&buff, "0123", 4);

    /* Try to read buffer */
    /* len holds number of bytes read */
    /* Read until len == 0, when buffer is empty */
    while ((len = ringbuff_read(&buff, data, sizeof(data))) > 0) {
        printf("Successfully read %d bytes\r\n", (int)len);
    }

Table of contents
^^^^^^^^^^^^^^^^^

.. toctree::
    :maxdepth: 2

    get-started/index
    user-manual/index
    tips-tricks/index
    api-reference/index
