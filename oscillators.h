#ifndef _FAS_OSCILLATORS_H_
#define _FAS_OSCILLATORS_H_

    #include <stdint.h>
    #include <math.h>

    #include "constants.h"
    #include "tools.h"

    struct oscillator {
        double freq;

        // filters fb
        double **fp1, **fp2, **fp3, **fp4;

#ifndef POLYBLEP
        int max_harmonics;
        float *harmonics;

    #ifdef FIXED_WAVETABLE
        uint16_t **harmo_phase_index;
        uint16_t *harmo_phase_step;
    #else
        unsigned int **harmo_phase_index;
        unsigned int *harmo_phase_step;
    #endif
#endif

#ifdef FIXED_WAVETABLE
        uint16_t *phase_index;
        uint16_t phase_step;

        // fm/pm
        uint16_t *phase_index2;
#else
        unsigned int *phase_index;
        unsigned int phase_step;

        // fm/pm
        unsigned int *phase_index2;
#endif
        double *fphase;

        float *pvalue;

        double phase_increment;

        double *buffer;
        unsigned int buffer_len;

        unsigned int triggered;

        uint16_t *noise_index;


    };

    extern struct oscillator *createOscillators(unsigned int n, double base_frequency, unsigned int octaves, unsigned int sample_rate, unsigned int wavetable_size, unsigned int frame_data_count);
    extern struct oscillator *freeOscillators(struct oscillator **oscs, unsigned int n, unsigned int frame_data_count);

    extern struct oscillator *copyOscillators(struct oscillator **oscs, unsigned int n, unsigned int frame_data_count);

#endif
