// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0
#pragma once

#include <frantic/channels/channel_map.hpp>

#include <krakatoa/particle_render_element_interface.hpp>
#include <krakatoa/render_element.hpp>

namespace krakatoa {

class shader_render_element : public render_element<particle_render_element_interface> {
    frantic::tstring m_elementName;
    frantic::channels::channel_const_cvt_accessor<frantic::graphics::color3f> m_accessor;

  public:
    shader_render_element( const frantic::tstring& elementName );
    virtual ~shader_render_element();

    /**
     * see render_element_interface::clone()
     */
    virtual render_element_interface* clone();

    /**
     * see particle_render_element_interface::get_drawing_type()
     */
    virtual draw_type get_drawing_type() const;

    /**
     * see particle_render_element_interface::set_channel_map()
     */
    virtual void set_channel_map( const frantic::channels::channel_map& pcm );

    /**
     * see particle_render_element_interface::add_required_channels()
     */
    virtual void add_required_channels( frantic::channels::channel_map& pcm );

    /**
     * see particle_render_element_interface::evaluate()
     */
    virtual frantic::graphics::color3f evaluate( const char* particle );

    /**
     * Retreives the name of the shader component that this render element captures
     */
    const frantic::tstring& get_element_name() const { return m_elementName; }
};

} // namespace krakatoa
