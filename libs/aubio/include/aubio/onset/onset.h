/*
  Copyright (C) 2006-2009 Paul Brossier <piem@aubio.org>

  This file is part of aubio.

  aubio is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  aubio is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with aubio.  If not, see <http://www.gnu.org/licenses/>.

*/

/** \file
 
  Onset detection driver

  The following routines compute the onset detection function and detect peaks
  in these functions. When onsets are found above a given silence threshold,
  and after a minimum inter-onset interval, the output vector returned by
  aubio_onset_do is filled with 1. Otherwise, the output vector remains 0.

  The peak-picking threshold, the silence threshold, and the minimum
  inter-onset interval can be adjusted during the execution of the
  aubio_onset_do routine using the corresponding functions.

*/
 

#ifndef ONSET_H
#define ONSET_H

#ifdef __cplusplus
extern "C" {
#endif

/** onset detection object */
typedef struct _aubio_onset_t aubio_onset_t;

/** create onset detection object
  
  \param method onset detection type as specified in specdesc.h
  \param buf_size buffer size for phase vocoder
  \param hop_size hop size for phase vocoder
  \param samplerate sampling rate of the input signal 

*/
aubio_onset_t * new_aubio_onset (char_t * method, 
    uint_t buf_size, uint_t hop_size, uint_t samplerate);

/** execute onset detection

  \param o onset detection object as returned by new_aubio_onset
  \param input new audio vector of length hop_size
  \param onset output vector, 1 if onset is found, 0 otherwise

*/
void aubio_onset_do (aubio_onset_t *o, fvec_t * input, fvec_t * onset);

/** set onset detection silence threshold

  \param o onset detection object as returned by new_aubio_onset
  \param silence new silence detection threshold

*/
uint_t aubio_onset_set_silence(aubio_onset_t * o, smpl_t silence);

/** set onset detection peak picking threshold 

  \param o onset detection object as returned by new_aubio_onset
  \param threshold new peak-picking threshold

*/
uint_t aubio_onset_set_threshold(aubio_onset_t * o, smpl_t threshold);

/** set minimum inter onset interval

  \param o onset detection object as returned by new_aubio_onset
  \param minioi minimum interval between two consecutive onsets (in
  milliseconds)

*/
uint_t aubio_onset_set_minioi(aubio_onset_t * o, uint_t minioi);

/** delete onset detection object

  \param o onset detection object to delete 

*/
void del_aubio_onset(aubio_onset_t * o);

#ifdef __cplusplus
}
#endif

#endif /* ONSET_H */
