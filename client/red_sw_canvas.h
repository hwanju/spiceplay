/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
   Copyright (C) 2009 Red Hat, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _H_CCANVAS
#define _H_CCANVAS

#include "canvas.h"
#include "sw_canvas.h"

class RedPixmap;

class SCanvas: public Canvas {
public:
    SCanvas(bool onscreen,
            int width, int height, uint32_t format, RedWindow *win,
            PixmapCache& pixmap_cache, PaletteCache& palette_cache,
            GlzDecoderWindow &glz_decoder_window, CSurfaces &csurfaces);
    virtual ~SCanvas();

    virtual void thread_touch() {}
    virtual void copy_pixels(const QRegion& region, RedDrawable* dc,
                             const PixmapHeader* pixmap);
    virtual void copy_pixels(const QRegion& region, RedDrawable& dc);
#ifdef USE_BENCHMARK
    virtual void set_record_info(FILE *record_fp, uint64_t record_start_time, bool is_record_display);
    virtual void record_pixels(SpiceRect rect);
    virtual int32_t check_snapshot_sync(uint32_t *snapshot_pixels, SpiceRect rect);
#endif
    virtual CanvasType get_pixmap_type();

private:
    RedPixmap *_pixmap;
    unsigned long _base;
    unsigned long _max;
#ifdef USE_BENCHMARK
    FILE *_record_fp;
    uint64_t _record_start_time;
    bool _is_record_display;
#endif
};

#endif

