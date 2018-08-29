

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DdsMsdc.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "DdsMsdc.hpp"
#include "DdsMsdcPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

namespace DdsJobMsdcAcqAdxl {

    // ---- alphaBeta: 

    alphaBeta::alphaBeta() :
        m_alpha_ (0.0f) ,
        m_beta_ (0.0f)  {
    }   

    alphaBeta::alphaBeta (
        float alpha,
        float beta)
        :
            m_alpha_( alpha ),
            m_beta_( beta ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    alphaBeta::alphaBeta(alphaBeta&& other_) OMG_NOEXCEPT  :m_alpha_ (std::move(other_.m_alpha_))
    ,
    m_beta_ (std::move(other_.m_beta_))
    {
    } 

    alphaBeta& alphaBeta::operator=(alphaBeta&&  other_) OMG_NOEXCEPT {
        alphaBeta tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void alphaBeta::swap(alphaBeta& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_alpha_, other_.m_alpha_);
        swap(m_beta_, other_.m_beta_);
    }  

    bool alphaBeta::operator == (const alphaBeta& other_) const {
        if (m_alpha_ != other_.m_alpha_) {
            return false;
        }
        if (m_beta_ != other_.m_beta_) {
            return false;
        }
        return true;
    }
    bool alphaBeta::operator != (const alphaBeta& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcAcqAdxl::alphaBeta::alpha() OMG_NOEXCEPT {
        return m_alpha_;
    }

    const float& DdsJobMsdcAcqAdxl::alphaBeta::alpha() const OMG_NOEXCEPT {
        return m_alpha_;
    }

    void DdsJobMsdcAcqAdxl::alphaBeta::alpha(float value) {
        m_alpha_ = value;
    }

    float& DdsJobMsdcAcqAdxl::alphaBeta::beta() OMG_NOEXCEPT {
        return m_beta_;
    }

    const float& DdsJobMsdcAcqAdxl::alphaBeta::beta() const OMG_NOEXCEPT {
        return m_beta_;
    }

    void DdsJobMsdcAcqAdxl::alphaBeta::beta(float value) {
        m_beta_ = value;
    }

    std::ostream& operator << (std::ostream& o,const alphaBeta& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "alpha: " << std::setprecision(9) <<sample.alpha()<<", ";
        o << "beta: " << std::setprecision(9) <<sample.beta() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobMsdcAcqAdxl  
namespace DdsJobMsdcAcqLwir {

    // ---- setOutput_req: 

    setOutput_req::setOutput_req()  {
    }   

    setOutput_req::setOutput_req (
        const vecsref& srefIxMsdcVSqrgrp)
        :
            m_srefIxMsdcVSqrgrp_( srefIxMsdcVSqrgrp ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setOutput_req::setOutput_req(setOutput_req&& other_) OMG_NOEXCEPT  :m_srefIxMsdcVSqrgrp_ (std::move(other_.m_srefIxMsdcVSqrgrp_))
    {
    } 

    setOutput_req& setOutput_req::operator=(setOutput_req&&  other_) OMG_NOEXCEPT {
        setOutput_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setOutput_req::swap(setOutput_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_srefIxMsdcVSqrgrp_, other_.m_srefIxMsdcVSqrgrp_);
    }  

    bool setOutput_req::operator == (const setOutput_req& other_) const {
        if (m_srefIxMsdcVSqrgrp_ != other_.m_srefIxMsdcVSqrgrp_) {
            return false;
        }
        return true;
    }
    bool setOutput_req::operator != (const setOutput_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    vecsref& DdsJobMsdcAcqLwir::setOutput_req::srefIxMsdcVSqrgrp() OMG_NOEXCEPT {
        return m_srefIxMsdcVSqrgrp_;
    }

    const vecsref& DdsJobMsdcAcqLwir::setOutput_req::srefIxMsdcVSqrgrp() const OMG_NOEXCEPT {
        return m_srefIxMsdcVSqrgrp_;
    }

    void DdsJobMsdcAcqLwir::setOutput_req::srefIxMsdcVSqrgrp(const vecsref& value) {
        m_srefIxMsdcVSqrgrp_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setOutput_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "srefIxMsdcVSqrgrp: " << sample.srefIxMsdcVSqrgrp() ;
        o <<"]";
        return o;
    }

    // ---- setOutput_reply: 

    setOutput_reply::setOutput_reply() :
        m_success_ (false)  {
    }   

    setOutput_reply::setOutput_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setOutput_reply::setOutput_reply(setOutput_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setOutput_reply& setOutput_reply::operator=(setOutput_reply&&  other_) OMG_NOEXCEPT {
        setOutput_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setOutput_reply::swap(setOutput_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setOutput_reply::operator == (const setOutput_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setOutput_reply::operator != (const setOutput_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqLwir::setOutput_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqLwir::setOutput_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqLwir::setOutput_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setOutput_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- start_req: 

    start_req::start_req() :
        m_dummy_ (false)  {
    }   

    start_req::start_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_req::start_req(start_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    start_req& start_req::operator=(start_req&&  other_) OMG_NOEXCEPT {
        start_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_req::swap(start_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool start_req::operator == (const start_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool start_req::operator != (const start_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqLwir::start_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcAcqLwir::start_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcAcqLwir::start_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- start_reply: 

    start_reply::start_reply() :
        m_success_ (false)  {
    }   

    start_reply::start_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_reply::start_reply(start_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    start_reply& start_reply::operator=(start_reply&&  other_) OMG_NOEXCEPT {
        start_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_reply::swap(start_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool start_reply::operator == (const start_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool start_reply::operator != (const start_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqLwir::start_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqLwir::start_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqLwir::start_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- stop_req: 

    stop_req::stop_req() :
        m_dummy_ (false)  {
    }   

    stop_req::stop_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_req::stop_req(stop_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    stop_req& stop_req::operator=(stop_req&&  other_) OMG_NOEXCEPT {
        stop_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_req::swap(stop_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool stop_req::operator == (const stop_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool stop_req::operator != (const stop_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqLwir::stop_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcAcqLwir::stop_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcAcqLwir::stop_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- stop_reply: 

    stop_reply::stop_reply() :
        m_success_ (false)  {
    }   

    stop_reply::stop_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_reply::stop_reply(stop_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    stop_reply& stop_reply::operator=(stop_reply&&  other_) OMG_NOEXCEPT {
        stop_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_reply::swap(stop_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool stop_reply::operator == (const stop_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool stop_reply::operator != (const stop_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqLwir::stop_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqLwir::stop_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqLwir::stop_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- seqnoTGray16: 

    seqnoTGray16::seqnoTGray16() :
        m_t_ (0.0)  {
            m_seqno_ = rti::topic::cdr::alias_helper<uint>::default_value();
    }   

    seqnoTGray16::seqnoTGray16 (
        const uint& seqno,
        double t,
        const rti::core::bounded_sequence<uint16_t, 19200>& gray16)
        :
            m_seqno_( seqno ),
            m_t_( t ),
            m_gray16_( gray16 ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    seqnoTGray16::seqnoTGray16(seqnoTGray16&& other_) OMG_NOEXCEPT  :m_seqno_ (std::move(other_.m_seqno_))
    ,
    m_t_ (std::move(other_.m_t_))
    ,
    m_gray16_ (std::move(other_.m_gray16_))
    {
    } 

    seqnoTGray16& seqnoTGray16::operator=(seqnoTGray16&&  other_) OMG_NOEXCEPT {
        seqnoTGray16 tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void seqnoTGray16::swap(seqnoTGray16& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_seqno_, other_.m_seqno_);
        swap(m_t_, other_.m_t_);
        swap(m_gray16_, other_.m_gray16_);
    }  

    bool seqnoTGray16::operator == (const seqnoTGray16& other_) const {
        if (m_seqno_ != other_.m_seqno_) {
            return false;
        }
        if (m_t_ != other_.m_t_) {
            return false;
        }
        if (m_gray16_ != other_.m_gray16_) {
            return false;
        }
        return true;
    }
    bool seqnoTGray16::operator != (const seqnoTGray16& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    uint& DdsJobMsdcAcqLwir::seqnoTGray16::seqno() OMG_NOEXCEPT {
        return m_seqno_;
    }

    const uint& DdsJobMsdcAcqLwir::seqnoTGray16::seqno() const OMG_NOEXCEPT {
        return m_seqno_;
    }

    void DdsJobMsdcAcqLwir::seqnoTGray16::seqno(const uint& value) {
        m_seqno_ = value;
    }

    double& DdsJobMsdcAcqLwir::seqnoTGray16::t() OMG_NOEXCEPT {
        return m_t_;
    }

    const double& DdsJobMsdcAcqLwir::seqnoTGray16::t() const OMG_NOEXCEPT {
        return m_t_;
    }

    void DdsJobMsdcAcqLwir::seqnoTGray16::t(double value) {
        m_t_ = value;
    }

    rti::core::bounded_sequence<uint16_t, 19200>& DdsJobMsdcAcqLwir::seqnoTGray16::gray16() OMG_NOEXCEPT {
        return m_gray16_;
    }

    const rti::core::bounded_sequence<uint16_t, 19200>& DdsJobMsdcAcqLwir::seqnoTGray16::gray16() const OMG_NOEXCEPT {
        return m_gray16_;
    }

    void DdsJobMsdcAcqLwir::seqnoTGray16::gray16(const rti::core::bounded_sequence<uint16_t, 19200>& value) {
        m_gray16_ = value;
    }

    std::ostream& operator << (std::ostream& o,const seqnoTGray16& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "seqno: " << sample.seqno()<<", ";
        o << "t: " << std::setprecision(15) <<sample.t()<<", ";
        o << "gray16: " << sample.gray16() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobMsdcAcqLwir  
namespace DdsJobMsdcAcqVisl {

    // ---- setFocus_req: 

    setFocus_req::setFocus_req() :
        m_focus_ (0.0f)  {
    }   

    setFocus_req::setFocus_req (
        float focus)
        :
            m_focus_( focus ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFocus_req::setFocus_req(setFocus_req&& other_) OMG_NOEXCEPT  :m_focus_ (std::move(other_.m_focus_))
    {
    } 

    setFocus_req& setFocus_req::operator=(setFocus_req&&  other_) OMG_NOEXCEPT {
        setFocus_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFocus_req::swap(setFocus_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_focus_, other_.m_focus_);
    }  

    bool setFocus_req::operator == (const setFocus_req& other_) const {
        if (m_focus_ != other_.m_focus_) {
            return false;
        }
        return true;
    }
    bool setFocus_req::operator != (const setFocus_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcAcqVisl::setFocus_req::focus() OMG_NOEXCEPT {
        return m_focus_;
    }

    const float& DdsJobMsdcAcqVisl::setFocus_req::focus() const OMG_NOEXCEPT {
        return m_focus_;
    }

    void DdsJobMsdcAcqVisl::setFocus_req::focus(float value) {
        m_focus_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setFocus_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "focus: " << std::setprecision(9) <<sample.focus() ;
        o <<"]";
        return o;
    }

    // ---- setFocus_reply: 

    setFocus_reply::setFocus_reply() :
        m_success_ (false)  {
    }   

    setFocus_reply::setFocus_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFocus_reply::setFocus_reply(setFocus_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setFocus_reply& setFocus_reply::operator=(setFocus_reply&&  other_) OMG_NOEXCEPT {
        setFocus_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFocus_reply::swap(setFocus_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setFocus_reply::operator == (const setFocus_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setFocus_reply::operator != (const setFocus_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisl::setFocus_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisl::setFocus_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisl::setFocus_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setFocus_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setOutput_req: 

    setOutput_req::setOutput_req() :
        m_grayscale_ (false)  {
    }   

    setOutput_req::setOutput_req (
        const vecsref& srefIxMsdcVCamres,
        const vecsref& srefIxMsdcVSqrgrp,
        bool grayscale)
        :
            m_srefIxMsdcVCamres_( srefIxMsdcVCamres ),
            m_srefIxMsdcVSqrgrp_( srefIxMsdcVSqrgrp ),
            m_grayscale_( grayscale ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setOutput_req::setOutput_req(setOutput_req&& other_) OMG_NOEXCEPT  :m_srefIxMsdcVCamres_ (std::move(other_.m_srefIxMsdcVCamres_))
    ,
    m_srefIxMsdcVSqrgrp_ (std::move(other_.m_srefIxMsdcVSqrgrp_))
    ,
    m_grayscale_ (std::move(other_.m_grayscale_))
    {
    } 

    setOutput_req& setOutput_req::operator=(setOutput_req&&  other_) OMG_NOEXCEPT {
        setOutput_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setOutput_req::swap(setOutput_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_srefIxMsdcVCamres_, other_.m_srefIxMsdcVCamres_);
        swap(m_srefIxMsdcVSqrgrp_, other_.m_srefIxMsdcVSqrgrp_);
        swap(m_grayscale_, other_.m_grayscale_);
    }  

    bool setOutput_req::operator == (const setOutput_req& other_) const {
        if (m_srefIxMsdcVCamres_ != other_.m_srefIxMsdcVCamres_) {
            return false;
        }
        if (m_srefIxMsdcVSqrgrp_ != other_.m_srefIxMsdcVSqrgrp_) {
            return false;
        }
        if (m_grayscale_ != other_.m_grayscale_) {
            return false;
        }
        return true;
    }
    bool setOutput_req::operator != (const setOutput_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    vecsref& DdsJobMsdcAcqVisl::setOutput_req::srefIxMsdcVCamres() OMG_NOEXCEPT {
        return m_srefIxMsdcVCamres_;
    }

    const vecsref& DdsJobMsdcAcqVisl::setOutput_req::srefIxMsdcVCamres() const OMG_NOEXCEPT {
        return m_srefIxMsdcVCamres_;
    }

    void DdsJobMsdcAcqVisl::setOutput_req::srefIxMsdcVCamres(const vecsref& value) {
        m_srefIxMsdcVCamres_ = value;
    }

    vecsref& DdsJobMsdcAcqVisl::setOutput_req::srefIxMsdcVSqrgrp() OMG_NOEXCEPT {
        return m_srefIxMsdcVSqrgrp_;
    }

    const vecsref& DdsJobMsdcAcqVisl::setOutput_req::srefIxMsdcVSqrgrp() const OMG_NOEXCEPT {
        return m_srefIxMsdcVSqrgrp_;
    }

    void DdsJobMsdcAcqVisl::setOutput_req::srefIxMsdcVSqrgrp(const vecsref& value) {
        m_srefIxMsdcVSqrgrp_ = value;
    }

    bool& DdsJobMsdcAcqVisl::setOutput_req::grayscale() OMG_NOEXCEPT {
        return m_grayscale_;
    }

    const bool& DdsJobMsdcAcqVisl::setOutput_req::grayscale() const OMG_NOEXCEPT {
        return m_grayscale_;
    }

    void DdsJobMsdcAcqVisl::setOutput_req::grayscale(bool value) {
        m_grayscale_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setOutput_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "srefIxMsdcVCamres: " << sample.srefIxMsdcVCamres()<<", ";
        o << "srefIxMsdcVSqrgrp: " << sample.srefIxMsdcVSqrgrp()<<", ";
        o << "grayscale: " << sample.grayscale() ;
        o <<"]";
        return o;
    }

    // ---- setOutput_reply: 

    setOutput_reply::setOutput_reply() :
        m_success_ (false)  {
    }   

    setOutput_reply::setOutput_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setOutput_reply::setOutput_reply(setOutput_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setOutput_reply& setOutput_reply::operator=(setOutput_reply&&  other_) OMG_NOEXCEPT {
        setOutput_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setOutput_reply::swap(setOutput_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setOutput_reply::operator == (const setOutput_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setOutput_reply::operator != (const setOutput_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisl::setOutput_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisl::setOutput_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisl::setOutput_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setOutput_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setTint_req: 

    setTint_req::setTint_req() :
        m_Tint_ (0.0f)  {
    }   

    setTint_req::setTint_req (
        float Tint)
        :
            m_Tint_( Tint ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setTint_req::setTint_req(setTint_req&& other_) OMG_NOEXCEPT  :m_Tint_ (std::move(other_.m_Tint_))
    {
    } 

    setTint_req& setTint_req::operator=(setTint_req&&  other_) OMG_NOEXCEPT {
        setTint_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setTint_req::swap(setTint_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_Tint_, other_.m_Tint_);
    }  

    bool setTint_req::operator == (const setTint_req& other_) const {
        if (m_Tint_ != other_.m_Tint_) {
            return false;
        }
        return true;
    }
    bool setTint_req::operator != (const setTint_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcAcqVisl::setTint_req::Tint() OMG_NOEXCEPT {
        return m_Tint_;
    }

    const float& DdsJobMsdcAcqVisl::setTint_req::Tint() const OMG_NOEXCEPT {
        return m_Tint_;
    }

    void DdsJobMsdcAcqVisl::setTint_req::Tint(float value) {
        m_Tint_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setTint_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Tint: " << std::setprecision(9) <<sample.Tint() ;
        o <<"]";
        return o;
    }

    // ---- setTint_reply: 

    setTint_reply::setTint_reply() :
        m_success_ (false)  {
    }   

    setTint_reply::setTint_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setTint_reply::setTint_reply(setTint_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setTint_reply& setTint_reply::operator=(setTint_reply&&  other_) OMG_NOEXCEPT {
        setTint_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setTint_reply::swap(setTint_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setTint_reply::operator == (const setTint_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setTint_reply::operator != (const setTint_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisl::setTint_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisl::setTint_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisl::setTint_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setTint_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- start_req: 

    start_req::start_req() :
        m_dummy_ (false)  {
    }   

    start_req::start_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_req::start_req(start_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    start_req& start_req::operator=(start_req&&  other_) OMG_NOEXCEPT {
        start_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_req::swap(start_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool start_req::operator == (const start_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool start_req::operator != (const start_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisl::start_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcAcqVisl::start_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcAcqVisl::start_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- start_reply: 

    start_reply::start_reply() :
        m_success_ (false)  {
    }   

    start_reply::start_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_reply::start_reply(start_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    start_reply& start_reply::operator=(start_reply&&  other_) OMG_NOEXCEPT {
        start_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_reply::swap(start_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool start_reply::operator == (const start_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool start_reply::operator != (const start_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisl::start_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisl::start_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisl::start_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- stop_req: 

    stop_req::stop_req() :
        m_dummy_ (false)  {
    }   

    stop_req::stop_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_req::stop_req(stop_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    stop_req& stop_req::operator=(stop_req&&  other_) OMG_NOEXCEPT {
        stop_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_req::swap(stop_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool stop_req::operator == (const stop_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool stop_req::operator != (const stop_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisl::stop_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcAcqVisl::stop_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcAcqVisl::stop_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- stop_reply: 

    stop_reply::stop_reply() :
        m_success_ (false)  {
    }   

    stop_reply::stop_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_reply::stop_reply(stop_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    stop_reply& stop_reply::operator=(stop_reply&&  other_) OMG_NOEXCEPT {
        stop_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_reply::swap(stop_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool stop_reply::operator == (const stop_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool stop_reply::operator != (const stop_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisl::stop_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisl::stop_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisl::stop_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- seqnoTRgbx8Gray8: 

    seqnoTRgbx8Gray8::seqnoTRgbx8Gray8() :
        m_t_ (0.0)  {
            m_seqno_ = rti::topic::cdr::alias_helper<uint>::default_value();
    }   

    seqnoTRgbx8Gray8::seqnoTRgbx8Gray8 (
        const uint& seqno,
        double t,
        const rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8,
        const rti::core::bounded_sequence<uint8_t, 1228800>& gray8)
        :
            m_seqno_( seqno ),
            m_t_( t ),
            m_rgbx8_( rgbx8 ),
            m_gray8_( gray8 ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    seqnoTRgbx8Gray8::seqnoTRgbx8Gray8(seqnoTRgbx8Gray8&& other_) OMG_NOEXCEPT  :m_seqno_ (std::move(other_.m_seqno_))
    ,
    m_t_ (std::move(other_.m_t_))
    ,
    m_rgbx8_ (std::move(other_.m_rgbx8_))
    ,
    m_gray8_ (std::move(other_.m_gray8_))
    {
    } 

    seqnoTRgbx8Gray8& seqnoTRgbx8Gray8::operator=(seqnoTRgbx8Gray8&&  other_) OMG_NOEXCEPT {
        seqnoTRgbx8Gray8 tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void seqnoTRgbx8Gray8::swap(seqnoTRgbx8Gray8& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_seqno_, other_.m_seqno_);
        swap(m_t_, other_.m_t_);
        swap(m_rgbx8_, other_.m_rgbx8_);
        swap(m_gray8_, other_.m_gray8_);
    }  

    bool seqnoTRgbx8Gray8::operator == (const seqnoTRgbx8Gray8& other_) const {
        if (m_seqno_ != other_.m_seqno_) {
            return false;
        }
        if (m_t_ != other_.m_t_) {
            return false;
        }
        if (m_rgbx8_ != other_.m_rgbx8_) {
            return false;
        }
        if (m_gray8_ != other_.m_gray8_) {
            return false;
        }
        return true;
    }
    bool seqnoTRgbx8Gray8::operator != (const seqnoTRgbx8Gray8& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    uint& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::seqno() OMG_NOEXCEPT {
        return m_seqno_;
    }

    const uint& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::seqno() const OMG_NOEXCEPT {
        return m_seqno_;
    }

    void DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::seqno(const uint& value) {
        m_seqno_ = value;
    }

    double& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::t() OMG_NOEXCEPT {
        return m_t_;
    }

    const double& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::t() const OMG_NOEXCEPT {
        return m_t_;
    }

    void DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::t(double value) {
        m_t_ = value;
    }

    rti::core::bounded_sequence<uint8_t, 4915200>& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::rgbx8() OMG_NOEXCEPT {
        return m_rgbx8_;
    }

    const rti::core::bounded_sequence<uint8_t, 4915200>& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::rgbx8() const OMG_NOEXCEPT {
        return m_rgbx8_;
    }

    void DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::rgbx8(const rti::core::bounded_sequence<uint8_t, 4915200>& value) {
        m_rgbx8_ = value;
    }

    rti::core::bounded_sequence<uint8_t, 1228800>& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::gray8() OMG_NOEXCEPT {
        return m_gray8_;
    }

    const rti::core::bounded_sequence<uint8_t, 1228800>& DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::gray8() const OMG_NOEXCEPT {
        return m_gray8_;
    }

    void DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8::gray8(const rti::core::bounded_sequence<uint8_t, 1228800>& value) {
        m_gray8_ = value;
    }

    std::ostream& operator << (std::ostream& o,const seqnoTRgbx8Gray8& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "seqno: " << sample.seqno()<<", ";
        o << "t: " << std::setprecision(15) <<sample.t()<<", ";
        o << "rgbx8: " << sample.rgbx8()<<", ";
        o << "gray8: " << sample.gray8() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobMsdcAcqVisl  
namespace DdsJobMsdcAcqVisr {

    // ---- setFocus_req: 

    setFocus_req::setFocus_req() :
        m_focus_ (0.0f)  {
    }   

    setFocus_req::setFocus_req (
        float focus)
        :
            m_focus_( focus ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFocus_req::setFocus_req(setFocus_req&& other_) OMG_NOEXCEPT  :m_focus_ (std::move(other_.m_focus_))
    {
    } 

    setFocus_req& setFocus_req::operator=(setFocus_req&&  other_) OMG_NOEXCEPT {
        setFocus_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFocus_req::swap(setFocus_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_focus_, other_.m_focus_);
    }  

    bool setFocus_req::operator == (const setFocus_req& other_) const {
        if (m_focus_ != other_.m_focus_) {
            return false;
        }
        return true;
    }
    bool setFocus_req::operator != (const setFocus_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcAcqVisr::setFocus_req::focus() OMG_NOEXCEPT {
        return m_focus_;
    }

    const float& DdsJobMsdcAcqVisr::setFocus_req::focus() const OMG_NOEXCEPT {
        return m_focus_;
    }

    void DdsJobMsdcAcqVisr::setFocus_req::focus(float value) {
        m_focus_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setFocus_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "focus: " << std::setprecision(9) <<sample.focus() ;
        o <<"]";
        return o;
    }

    // ---- setFocus_reply: 

    setFocus_reply::setFocus_reply() :
        m_success_ (false)  {
    }   

    setFocus_reply::setFocus_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFocus_reply::setFocus_reply(setFocus_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setFocus_reply& setFocus_reply::operator=(setFocus_reply&&  other_) OMG_NOEXCEPT {
        setFocus_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFocus_reply::swap(setFocus_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setFocus_reply::operator == (const setFocus_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setFocus_reply::operator != (const setFocus_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisr::setFocus_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisr::setFocus_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisr::setFocus_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setFocus_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setOutput_req: 

    setOutput_req::setOutput_req() :
        m_grayscale_ (false)  {
    }   

    setOutput_req::setOutput_req (
        const vecsref& srefIxMsdcVCamres,
        const vecsref& srefIxMsdcVSqrgrp,
        bool grayscale)
        :
            m_srefIxMsdcVCamres_( srefIxMsdcVCamres ),
            m_srefIxMsdcVSqrgrp_( srefIxMsdcVSqrgrp ),
            m_grayscale_( grayscale ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setOutput_req::setOutput_req(setOutput_req&& other_) OMG_NOEXCEPT  :m_srefIxMsdcVCamres_ (std::move(other_.m_srefIxMsdcVCamres_))
    ,
    m_srefIxMsdcVSqrgrp_ (std::move(other_.m_srefIxMsdcVSqrgrp_))
    ,
    m_grayscale_ (std::move(other_.m_grayscale_))
    {
    } 

    setOutput_req& setOutput_req::operator=(setOutput_req&&  other_) OMG_NOEXCEPT {
        setOutput_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setOutput_req::swap(setOutput_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_srefIxMsdcVCamres_, other_.m_srefIxMsdcVCamres_);
        swap(m_srefIxMsdcVSqrgrp_, other_.m_srefIxMsdcVSqrgrp_);
        swap(m_grayscale_, other_.m_grayscale_);
    }  

    bool setOutput_req::operator == (const setOutput_req& other_) const {
        if (m_srefIxMsdcVCamres_ != other_.m_srefIxMsdcVCamres_) {
            return false;
        }
        if (m_srefIxMsdcVSqrgrp_ != other_.m_srefIxMsdcVSqrgrp_) {
            return false;
        }
        if (m_grayscale_ != other_.m_grayscale_) {
            return false;
        }
        return true;
    }
    bool setOutput_req::operator != (const setOutput_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    vecsref& DdsJobMsdcAcqVisr::setOutput_req::srefIxMsdcVCamres() OMG_NOEXCEPT {
        return m_srefIxMsdcVCamres_;
    }

    const vecsref& DdsJobMsdcAcqVisr::setOutput_req::srefIxMsdcVCamres() const OMG_NOEXCEPT {
        return m_srefIxMsdcVCamres_;
    }

    void DdsJobMsdcAcqVisr::setOutput_req::srefIxMsdcVCamres(const vecsref& value) {
        m_srefIxMsdcVCamres_ = value;
    }

    vecsref& DdsJobMsdcAcqVisr::setOutput_req::srefIxMsdcVSqrgrp() OMG_NOEXCEPT {
        return m_srefIxMsdcVSqrgrp_;
    }

    const vecsref& DdsJobMsdcAcqVisr::setOutput_req::srefIxMsdcVSqrgrp() const OMG_NOEXCEPT {
        return m_srefIxMsdcVSqrgrp_;
    }

    void DdsJobMsdcAcqVisr::setOutput_req::srefIxMsdcVSqrgrp(const vecsref& value) {
        m_srefIxMsdcVSqrgrp_ = value;
    }

    bool& DdsJobMsdcAcqVisr::setOutput_req::grayscale() OMG_NOEXCEPT {
        return m_grayscale_;
    }

    const bool& DdsJobMsdcAcqVisr::setOutput_req::grayscale() const OMG_NOEXCEPT {
        return m_grayscale_;
    }

    void DdsJobMsdcAcqVisr::setOutput_req::grayscale(bool value) {
        m_grayscale_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setOutput_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "srefIxMsdcVCamres: " << sample.srefIxMsdcVCamres()<<", ";
        o << "srefIxMsdcVSqrgrp: " << sample.srefIxMsdcVSqrgrp()<<", ";
        o << "grayscale: " << sample.grayscale() ;
        o <<"]";
        return o;
    }

    // ---- setOutput_reply: 

    setOutput_reply::setOutput_reply() :
        m_success_ (false)  {
    }   

    setOutput_reply::setOutput_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setOutput_reply::setOutput_reply(setOutput_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setOutput_reply& setOutput_reply::operator=(setOutput_reply&&  other_) OMG_NOEXCEPT {
        setOutput_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setOutput_reply::swap(setOutput_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setOutput_reply::operator == (const setOutput_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setOutput_reply::operator != (const setOutput_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisr::setOutput_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisr::setOutput_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisr::setOutput_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setOutput_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setTint_req: 

    setTint_req::setTint_req() :
        m_Tint_ (0.0f)  {
    }   

    setTint_req::setTint_req (
        float Tint)
        :
            m_Tint_( Tint ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setTint_req::setTint_req(setTint_req&& other_) OMG_NOEXCEPT  :m_Tint_ (std::move(other_.m_Tint_))
    {
    } 

    setTint_req& setTint_req::operator=(setTint_req&&  other_) OMG_NOEXCEPT {
        setTint_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setTint_req::swap(setTint_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_Tint_, other_.m_Tint_);
    }  

    bool setTint_req::operator == (const setTint_req& other_) const {
        if (m_Tint_ != other_.m_Tint_) {
            return false;
        }
        return true;
    }
    bool setTint_req::operator != (const setTint_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcAcqVisr::setTint_req::Tint() OMG_NOEXCEPT {
        return m_Tint_;
    }

    const float& DdsJobMsdcAcqVisr::setTint_req::Tint() const OMG_NOEXCEPT {
        return m_Tint_;
    }

    void DdsJobMsdcAcqVisr::setTint_req::Tint(float value) {
        m_Tint_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setTint_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Tint: " << std::setprecision(9) <<sample.Tint() ;
        o <<"]";
        return o;
    }

    // ---- setTint_reply: 

    setTint_reply::setTint_reply() :
        m_success_ (false)  {
    }   

    setTint_reply::setTint_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setTint_reply::setTint_reply(setTint_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setTint_reply& setTint_reply::operator=(setTint_reply&&  other_) OMG_NOEXCEPT {
        setTint_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setTint_reply::swap(setTint_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setTint_reply::operator == (const setTint_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setTint_reply::operator != (const setTint_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisr::setTint_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisr::setTint_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisr::setTint_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setTint_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- start_req: 

    start_req::start_req() :
        m_dummy_ (false)  {
    }   

    start_req::start_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_req::start_req(start_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    start_req& start_req::operator=(start_req&&  other_) OMG_NOEXCEPT {
        start_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_req::swap(start_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool start_req::operator == (const start_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool start_req::operator != (const start_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisr::start_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcAcqVisr::start_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcAcqVisr::start_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- start_reply: 

    start_reply::start_reply() :
        m_success_ (false)  {
    }   

    start_reply::start_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_reply::start_reply(start_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    start_reply& start_reply::operator=(start_reply&&  other_) OMG_NOEXCEPT {
        start_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_reply::swap(start_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool start_reply::operator == (const start_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool start_reply::operator != (const start_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisr::start_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisr::start_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisr::start_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- stop_req: 

    stop_req::stop_req() :
        m_dummy_ (false)  {
    }   

    stop_req::stop_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_req::stop_req(stop_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    stop_req& stop_req::operator=(stop_req&&  other_) OMG_NOEXCEPT {
        stop_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_req::swap(stop_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool stop_req::operator == (const stop_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool stop_req::operator != (const stop_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisr::stop_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcAcqVisr::stop_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcAcqVisr::stop_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- stop_reply: 

    stop_reply::stop_reply() :
        m_success_ (false)  {
    }   

    stop_reply::stop_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_reply::stop_reply(stop_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    stop_reply& stop_reply::operator=(stop_reply&&  other_) OMG_NOEXCEPT {
        stop_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_reply::swap(stop_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool stop_reply::operator == (const stop_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool stop_reply::operator != (const stop_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcAcqVisr::stop_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcAcqVisr::stop_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcAcqVisr::stop_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- seqnoTRgbx8Gray8: 

    seqnoTRgbx8Gray8::seqnoTRgbx8Gray8() :
        m_t_ (0.0)  {
            m_seqno_ = rti::topic::cdr::alias_helper<uint>::default_value();
    }   

    seqnoTRgbx8Gray8::seqnoTRgbx8Gray8 (
        const uint& seqno,
        double t,
        const rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8,
        const rti::core::bounded_sequence<uint8_t, 1228800>& gray8)
        :
            m_seqno_( seqno ),
            m_t_( t ),
            m_rgbx8_( rgbx8 ),
            m_gray8_( gray8 ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    seqnoTRgbx8Gray8::seqnoTRgbx8Gray8(seqnoTRgbx8Gray8&& other_) OMG_NOEXCEPT  :m_seqno_ (std::move(other_.m_seqno_))
    ,
    m_t_ (std::move(other_.m_t_))
    ,
    m_rgbx8_ (std::move(other_.m_rgbx8_))
    ,
    m_gray8_ (std::move(other_.m_gray8_))
    {
    } 

    seqnoTRgbx8Gray8& seqnoTRgbx8Gray8::operator=(seqnoTRgbx8Gray8&&  other_) OMG_NOEXCEPT {
        seqnoTRgbx8Gray8 tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void seqnoTRgbx8Gray8::swap(seqnoTRgbx8Gray8& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_seqno_, other_.m_seqno_);
        swap(m_t_, other_.m_t_);
        swap(m_rgbx8_, other_.m_rgbx8_);
        swap(m_gray8_, other_.m_gray8_);
    }  

    bool seqnoTRgbx8Gray8::operator == (const seqnoTRgbx8Gray8& other_) const {
        if (m_seqno_ != other_.m_seqno_) {
            return false;
        }
        if (m_t_ != other_.m_t_) {
            return false;
        }
        if (m_rgbx8_ != other_.m_rgbx8_) {
            return false;
        }
        if (m_gray8_ != other_.m_gray8_) {
            return false;
        }
        return true;
    }
    bool seqnoTRgbx8Gray8::operator != (const seqnoTRgbx8Gray8& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    uint& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::seqno() OMG_NOEXCEPT {
        return m_seqno_;
    }

    const uint& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::seqno() const OMG_NOEXCEPT {
        return m_seqno_;
    }

    void DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::seqno(const uint& value) {
        m_seqno_ = value;
    }

    double& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::t() OMG_NOEXCEPT {
        return m_t_;
    }

    const double& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::t() const OMG_NOEXCEPT {
        return m_t_;
    }

    void DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::t(double value) {
        m_t_ = value;
    }

    rti::core::bounded_sequence<uint8_t, 4915200>& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::rgbx8() OMG_NOEXCEPT {
        return m_rgbx8_;
    }

    const rti::core::bounded_sequence<uint8_t, 4915200>& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::rgbx8() const OMG_NOEXCEPT {
        return m_rgbx8_;
    }

    void DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::rgbx8(const rti::core::bounded_sequence<uint8_t, 4915200>& value) {
        m_rgbx8_ = value;
    }

    rti::core::bounded_sequence<uint8_t, 1228800>& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::gray8() OMG_NOEXCEPT {
        return m_gray8_;
    }

    const rti::core::bounded_sequence<uint8_t, 1228800>& DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::gray8() const OMG_NOEXCEPT {
        return m_gray8_;
    }

    void DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8::gray8(const rti::core::bounded_sequence<uint8_t, 1228800>& value) {
        m_gray8_ = value;
    }

    std::ostream& operator << (std::ostream& o,const seqnoTRgbx8Gray8& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "seqno: " << sample.seqno()<<", ";
        o << "t: " << std::setprecision(15) <<sample.t()<<", ";
        o << "rgbx8: " << sample.rgbx8()<<", ";
        o << "gray8: " << sample.gray8() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobMsdcAcqVisr  
namespace DdsJobMsdcActAlign {

    // ---- setWave_req: 

    setWave_req::setWave_req()  {
        m_N_ = rti::topic::cdr::alias_helper<utinyint>::default_value();
    }   

    setWave_req::setWave_req (
        const vecsref& srefIxVFunction,
        const utinyint& N,
        const rti::core::bounded_sequence<float, 32>& seq)
        :
            m_srefIxVFunction_( srefIxVFunction ),
            m_N_( N ),
            m_seq_( seq ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setWave_req::setWave_req(setWave_req&& other_) OMG_NOEXCEPT  :m_srefIxVFunction_ (std::move(other_.m_srefIxVFunction_))
    ,
    m_N_ (std::move(other_.m_N_))
    ,
    m_seq_ (std::move(other_.m_seq_))
    {
    } 

    setWave_req& setWave_req::operator=(setWave_req&&  other_) OMG_NOEXCEPT {
        setWave_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setWave_req::swap(setWave_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_srefIxVFunction_, other_.m_srefIxVFunction_);
        swap(m_N_, other_.m_N_);
        swap(m_seq_, other_.m_seq_);
    }  

    bool setWave_req::operator == (const setWave_req& other_) const {
        if (m_srefIxVFunction_ != other_.m_srefIxVFunction_) {
            return false;
        }
        if (m_N_ != other_.m_N_) {
            return false;
        }
        if (m_seq_ != other_.m_seq_) {
            return false;
        }
        return true;
    }
    bool setWave_req::operator != (const setWave_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    vecsref& DdsJobMsdcActAlign::setWave_req::srefIxVFunction() OMG_NOEXCEPT {
        return m_srefIxVFunction_;
    }

    const vecsref& DdsJobMsdcActAlign::setWave_req::srefIxVFunction() const OMG_NOEXCEPT {
        return m_srefIxVFunction_;
    }

    void DdsJobMsdcActAlign::setWave_req::srefIxVFunction(const vecsref& value) {
        m_srefIxVFunction_ = value;
    }

    utinyint& DdsJobMsdcActAlign::setWave_req::N() OMG_NOEXCEPT {
        return m_N_;
    }

    const utinyint& DdsJobMsdcActAlign::setWave_req::N() const OMG_NOEXCEPT {
        return m_N_;
    }

    void DdsJobMsdcActAlign::setWave_req::N(const utinyint& value) {
        m_N_ = value;
    }

    rti::core::bounded_sequence<float, 32>& DdsJobMsdcActAlign::setWave_req::seq() OMG_NOEXCEPT {
        return m_seq_;
    }

    const rti::core::bounded_sequence<float, 32>& DdsJobMsdcActAlign::setWave_req::seq() const OMG_NOEXCEPT {
        return m_seq_;
    }

    void DdsJobMsdcActAlign::setWave_req::seq(const rti::core::bounded_sequence<float, 32>& value) {
        m_seq_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setWave_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "srefIxVFunction: " << sample.srefIxVFunction()<<", ";
        o << "N: " << sample.N()<<", ";
        o << "seq: " << sample.seq() ;
        o <<"]";
        return o;
    }

    // ---- setWave_reply: 

    setWave_reply::setWave_reply() :
        m_success_ (false)  {
    }   

    setWave_reply::setWave_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setWave_reply::setWave_reply(setWave_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setWave_reply& setWave_reply::operator=(setWave_reply&&  other_) OMG_NOEXCEPT {
        setWave_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setWave_reply::swap(setWave_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setWave_reply::operator == (const setWave_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setWave_reply::operator != (const setWave_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActAlign::setWave_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcActAlign::setWave_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcActAlign::setWave_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setWave_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- start_req: 

    start_req::start_req() :
        m_dummy_ (false)  {
    }   

    start_req::start_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_req::start_req(start_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    start_req& start_req::operator=(start_req&&  other_) OMG_NOEXCEPT {
        start_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_req::swap(start_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool start_req::operator == (const start_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool start_req::operator != (const start_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActAlign::start_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcActAlign::start_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcActAlign::start_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- start_reply: 

    start_reply::start_reply() :
        m_success_ (false)  {
    }   

    start_reply::start_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    start_reply::start_reply(start_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    start_reply& start_reply::operator=(start_reply&&  other_) OMG_NOEXCEPT {
        start_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void start_reply::swap(start_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool start_reply::operator == (const start_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool start_reply::operator != (const start_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActAlign::start_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcActAlign::start_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcActAlign::start_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const start_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- stop_req: 

    stop_req::stop_req() :
        m_dummy_ (false)  {
    }   

    stop_req::stop_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_req::stop_req(stop_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    stop_req& stop_req::operator=(stop_req&&  other_) OMG_NOEXCEPT {
        stop_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_req::swap(stop_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool stop_req::operator == (const stop_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool stop_req::operator != (const stop_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActAlign::stop_req::dummy() OMG_NOEXCEPT {
        return m_dummy_;
    }

    const bool& DdsJobMsdcActAlign::stop_req::dummy() const OMG_NOEXCEPT {
        return m_dummy_;
    }

    void DdsJobMsdcActAlign::stop_req::dummy(bool value) {
        m_dummy_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- stop_reply: 

    stop_reply::stop_reply() :
        m_success_ (false)  {
    }   

    stop_reply::stop_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_reply::stop_reply(stop_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    stop_reply& stop_reply::operator=(stop_reply&&  other_) OMG_NOEXCEPT {
        stop_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_reply::swap(stop_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool stop_reply::operator == (const stop_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool stop_reply::operator != (const stop_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActAlign::stop_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcActAlign::stop_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcActAlign::stop_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const stop_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobMsdcActAlign  
namespace DdsJobMsdcActLed {

    // ---- setFlood_req: 

    setFlood_req::setFlood_req() :
        m_flood_ (0.0f)  {
    }   

    setFlood_req::setFlood_req (
        float flood)
        :
            m_flood_( flood ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFlood_req::setFlood_req(setFlood_req&& other_) OMG_NOEXCEPT  :m_flood_ (std::move(other_.m_flood_))
    {
    } 

    setFlood_req& setFlood_req::operator=(setFlood_req&&  other_) OMG_NOEXCEPT {
        setFlood_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFlood_req::swap(setFlood_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_flood_, other_.m_flood_);
    }  

    bool setFlood_req::operator == (const setFlood_req& other_) const {
        if (m_flood_ != other_.m_flood_) {
            return false;
        }
        return true;
    }
    bool setFlood_req::operator != (const setFlood_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcActLed::setFlood_req::flood() OMG_NOEXCEPT {
        return m_flood_;
    }

    const float& DdsJobMsdcActLed::setFlood_req::flood() const OMG_NOEXCEPT {
        return m_flood_;
    }

    void DdsJobMsdcActLed::setFlood_req::flood(float value) {
        m_flood_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setFlood_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "flood: " << std::setprecision(9) <<sample.flood() ;
        o <<"]";
        return o;
    }

    // ---- setFlood_reply: 

    setFlood_reply::setFlood_reply() :
        m_success_ (false)  {
    }   

    setFlood_reply::setFlood_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFlood_reply::setFlood_reply(setFlood_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setFlood_reply& setFlood_reply::operator=(setFlood_reply&&  other_) OMG_NOEXCEPT {
        setFlood_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFlood_reply::swap(setFlood_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setFlood_reply::operator == (const setFlood_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setFlood_reply::operator != (const setFlood_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActLed::setFlood_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcActLed::setFlood_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcActLed::setFlood_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setFlood_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setSpot_req: 

    setSpot_req::setSpot_req() :
        m_spot_ (0.0f)  {
    }   

    setSpot_req::setSpot_req (
        float spot)
        :
            m_spot_( spot ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setSpot_req::setSpot_req(setSpot_req&& other_) OMG_NOEXCEPT  :m_spot_ (std::move(other_.m_spot_))
    {
    } 

    setSpot_req& setSpot_req::operator=(setSpot_req&&  other_) OMG_NOEXCEPT {
        setSpot_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setSpot_req::swap(setSpot_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_spot_, other_.m_spot_);
    }  

    bool setSpot_req::operator == (const setSpot_req& other_) const {
        if (m_spot_ != other_.m_spot_) {
            return false;
        }
        return true;
    }
    bool setSpot_req::operator != (const setSpot_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcActLed::setSpot_req::spot() OMG_NOEXCEPT {
        return m_spot_;
    }

    const float& DdsJobMsdcActLed::setSpot_req::spot() const OMG_NOEXCEPT {
        return m_spot_;
    }

    void DdsJobMsdcActLed::setSpot_req::spot(float value) {
        m_spot_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setSpot_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "spot: " << std::setprecision(9) <<sample.spot() ;
        o <<"]";
        return o;
    }

    // ---- setSpot_reply: 

    setSpot_reply::setSpot_reply() :
        m_success_ (false)  {
    }   

    setSpot_reply::setSpot_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setSpot_reply::setSpot_reply(setSpot_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setSpot_reply& setSpot_reply::operator=(setSpot_reply&&  other_) OMG_NOEXCEPT {
        setSpot_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setSpot_reply::swap(setSpot_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setSpot_reply::operator == (const setSpot_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setSpot_reply::operator != (const setSpot_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActLed::setSpot_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcActLed::setSpot_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcActLed::setSpot_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setSpot_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- floodSpot: 

    floodSpot::floodSpot() :
        m_flood_ (0.0f) ,
        m_spot_ (0.0f)  {
    }   

    floodSpot::floodSpot (
        float flood,
        float spot)
        :
            m_flood_( flood ),
            m_spot_( spot ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    floodSpot::floodSpot(floodSpot&& other_) OMG_NOEXCEPT  :m_flood_ (std::move(other_.m_flood_))
    ,
    m_spot_ (std::move(other_.m_spot_))
    {
    } 

    floodSpot& floodSpot::operator=(floodSpot&&  other_) OMG_NOEXCEPT {
        floodSpot tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void floodSpot::swap(floodSpot& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_flood_, other_.m_flood_);
        swap(m_spot_, other_.m_spot_);
    }  

    bool floodSpot::operator == (const floodSpot& other_) const {
        if (m_flood_ != other_.m_flood_) {
            return false;
        }
        if (m_spot_ != other_.m_spot_) {
            return false;
        }
        return true;
    }
    bool floodSpot::operator != (const floodSpot& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcActLed::floodSpot::flood() OMG_NOEXCEPT {
        return m_flood_;
    }

    const float& DdsJobMsdcActLed::floodSpot::flood() const OMG_NOEXCEPT {
        return m_flood_;
    }

    void DdsJobMsdcActLed::floodSpot::flood(float value) {
        m_flood_ = value;
    }

    float& DdsJobMsdcActLed::floodSpot::spot() OMG_NOEXCEPT {
        return m_spot_;
    }

    const float& DdsJobMsdcActLed::floodSpot::spot() const OMG_NOEXCEPT {
        return m_spot_;
    }

    void DdsJobMsdcActLed::floodSpot::spot(float value) {
        m_spot_ = value;
    }

    std::ostream& operator << (std::ostream& o,const floodSpot& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "flood: " << std::setprecision(9) <<sample.flood()<<", ";
        o << "spot: " << std::setprecision(9) <<sample.spot() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobMsdcActLed  
namespace DdsJobMsdcActServo {

    // ---- setPhi_req: 

    setPhi_req::setPhi_req() :
        m_phi_ (0.0f)  {
    }   

    setPhi_req::setPhi_req (
        float phi)
        :
            m_phi_( phi ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setPhi_req::setPhi_req(setPhi_req&& other_) OMG_NOEXCEPT  :m_phi_ (std::move(other_.m_phi_))
    {
    } 

    setPhi_req& setPhi_req::operator=(setPhi_req&&  other_) OMG_NOEXCEPT {
        setPhi_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setPhi_req::swap(setPhi_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_phi_, other_.m_phi_);
    }  

    bool setPhi_req::operator == (const setPhi_req& other_) const {
        if (m_phi_ != other_.m_phi_) {
            return false;
        }
        return true;
    }
    bool setPhi_req::operator != (const setPhi_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcActServo::setPhi_req::phi() OMG_NOEXCEPT {
        return m_phi_;
    }

    const float& DdsJobMsdcActServo::setPhi_req::phi() const OMG_NOEXCEPT {
        return m_phi_;
    }

    void DdsJobMsdcActServo::setPhi_req::phi(float value) {
        m_phi_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setPhi_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "phi: " << std::setprecision(9) <<sample.phi() ;
        o <<"]";
        return o;
    }

    // ---- setPhi_reply: 

    setPhi_reply::setPhi_reply() :
        m_success_ (false)  {
    }   

    setPhi_reply::setPhi_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setPhi_reply::setPhi_reply(setPhi_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setPhi_reply& setPhi_reply::operator=(setPhi_reply&&  other_) OMG_NOEXCEPT {
        setPhi_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setPhi_reply::swap(setPhi_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setPhi_reply::operator == (const setPhi_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setPhi_reply::operator != (const setPhi_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActServo::setPhi_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcActServo::setPhi_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcActServo::setPhi_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setPhi_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setTheta_req: 

    setTheta_req::setTheta_req() :
        m_theta_ (0.0f)  {
    }   

    setTheta_req::setTheta_req (
        float theta)
        :
            m_theta_( theta ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setTheta_req::setTheta_req(setTheta_req&& other_) OMG_NOEXCEPT  :m_theta_ (std::move(other_.m_theta_))
    {
    } 

    setTheta_req& setTheta_req::operator=(setTheta_req&&  other_) OMG_NOEXCEPT {
        setTheta_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setTheta_req::swap(setTheta_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_theta_, other_.m_theta_);
    }  

    bool setTheta_req::operator == (const setTheta_req& other_) const {
        if (m_theta_ != other_.m_theta_) {
            return false;
        }
        return true;
    }
    bool setTheta_req::operator != (const setTheta_req& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcActServo::setTheta_req::theta() OMG_NOEXCEPT {
        return m_theta_;
    }

    const float& DdsJobMsdcActServo::setTheta_req::theta() const OMG_NOEXCEPT {
        return m_theta_;
    }

    void DdsJobMsdcActServo::setTheta_req::theta(float value) {
        m_theta_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setTheta_req& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "theta: " << std::setprecision(9) <<sample.theta() ;
        o <<"]";
        return o;
    }

    // ---- setTheta_reply: 

    setTheta_reply::setTheta_reply() :
        m_success_ (false)  {
    }   

    setTheta_reply::setTheta_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setTheta_reply::setTheta_reply(setTheta_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setTheta_reply& setTheta_reply::operator=(setTheta_reply&&  other_) OMG_NOEXCEPT {
        setTheta_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setTheta_reply::swap(setTheta_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setTheta_reply::operator == (const setTheta_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setTheta_reply::operator != (const setTheta_reply& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    bool& DdsJobMsdcActServo::setTheta_reply::success() OMG_NOEXCEPT {
        return m_success_;
    }

    const bool& DdsJobMsdcActServo::setTheta_reply::success() const OMG_NOEXCEPT {
        return m_success_;
    }

    void DdsJobMsdcActServo::setTheta_reply::success(bool value) {
        m_success_ = value;
    }

    std::ostream& operator << (std::ostream& o,const setTheta_reply& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- thetaPhi: 

    thetaPhi::thetaPhi() :
        m_theta_ (0.0f) ,
        m_phi_ (0.0f)  {
    }   

    thetaPhi::thetaPhi (
        float theta,
        float phi)
        :
            m_theta_( theta ),
            m_phi_( phi ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    thetaPhi::thetaPhi(thetaPhi&& other_) OMG_NOEXCEPT  :m_theta_ (std::move(other_.m_theta_))
    ,
    m_phi_ (std::move(other_.m_phi_))
    {
    } 

    thetaPhi& thetaPhi::operator=(thetaPhi&&  other_) OMG_NOEXCEPT {
        thetaPhi tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void thetaPhi::swap(thetaPhi& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_theta_, other_.m_theta_);
        swap(m_phi_, other_.m_phi_);
    }  

    bool thetaPhi::operator == (const thetaPhi& other_) const {
        if (m_theta_ != other_.m_theta_) {
            return false;
        }
        if (m_phi_ != other_.m_phi_) {
            return false;
        }
        return true;
    }
    bool thetaPhi::operator != (const thetaPhi& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    float& DdsJobMsdcActServo::thetaPhi::theta() OMG_NOEXCEPT {
        return m_theta_;
    }

    const float& DdsJobMsdcActServo::thetaPhi::theta() const OMG_NOEXCEPT {
        return m_theta_;
    }

    void DdsJobMsdcActServo::thetaPhi::theta(float value) {
        m_theta_ = value;
    }

    float& DdsJobMsdcActServo::thetaPhi::phi() OMG_NOEXCEPT {
        return m_phi_;
    }

    const float& DdsJobMsdcActServo::thetaPhi::phi() const OMG_NOEXCEPT {
        return m_phi_;
    }

    void DdsJobMsdcActServo::thetaPhi::phi(float value) {
        m_phi_ = value;
    }

    std::ostream& operator << (std::ostream& o,const thetaPhi& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "theta: " << std::setprecision(9) <<sample.theta()<<", ";
        o << "phi: " << std::setprecision(9) <<sample.phi() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobMsdcActServo  

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<tinyint_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode tinyint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"tinyint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  tinyint */

                if (is_initialized) {
                    return &tinyint_g_tc;
                }

                tinyint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_char;

                is_initialized = RTI_TRUE;

                return &tinyint_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<tinyint_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<tinyint_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<utinyint_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode utinyint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"utinyint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  utinyint */

                if (is_initialized) {
                    return &utinyint_g_tc;
                }

                utinyint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_octet;

                is_initialized = RTI_TRUE;

                return &utinyint_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<utinyint_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<utinyint_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<smallint_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode smallint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"smallint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  smallint */

                if (is_initialized) {
                    return &smallint_g_tc;
                }

                smallint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_short;

                is_initialized = RTI_TRUE;

                return &smallint_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<smallint_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<smallint_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<usmallint_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode usmallint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"usmallint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  usmallint */

                if (is_initialized) {
                    return &usmallint_g_tc;
                }

                usmallint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_ushort;

                is_initialized = RTI_TRUE;

                return &usmallint_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<usmallint_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<usmallint_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<_cxx_int_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode _cxx_int_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"int", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  _cxx_int */

                if (is_initialized) {
                    return &_cxx_int_g_tc;
                }

                _cxx_int_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_long;

                is_initialized = RTI_TRUE;

                return &_cxx_int_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<_cxx_int_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<_cxx_int_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<uint_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode uint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"uint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  uint */

                if (is_initialized) {
                    return &uint_g_tc;
                }

                uint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_ulong;

                is_initialized = RTI_TRUE;

                return &uint_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<uint_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<uint_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<bigint_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode bigint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"bigint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  bigint */

                if (is_initialized) {
                    return &bigint_g_tc;
                }

                bigint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_longlong;

                is_initialized = RTI_TRUE;

                return &bigint_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<bigint_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<bigint_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<ubigint_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ubigint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"ubigint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  ubigint */

                if (is_initialized) {
                    return &ubigint_g_tc;
                }

                ubigint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_ulonglong;

                is_initialized = RTI_TRUE;

                return &ubigint_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<ubigint_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<ubigint_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<vecsref_AliasTag_t> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode vecsref_g_tc_string = DDS_INITIALIZE_STRING_TYPECODE((50));

                static DDS_TypeCode vecsref_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"vecsref", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE /* Ignored */
                    }}; /* Type code for  vecsref */

                if (is_initialized) {
                    return &vecsref_g_tc;
                }

                vecsref_g_tc._data._typeCode =  (RTICdrTypeCode *)&vecsref_g_tc_string;

                is_initialized = RTI_TRUE;

                return &vecsref_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::AliasType& dynamic_type<vecsref_AliasTag_t>::get()
        {
            return static_cast<const dds::core::xtypes::AliasType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<vecsref_AliasTag_t>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqAdxl::alphaBeta> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member alphaBeta_g_tc_members[2]=
                {

                    {
                        (char *)"alpha",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"beta",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode alphaBeta_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqAdxl::alphaBeta", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        alphaBeta_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for alphaBeta*/

                if (is_initialized) {
                    return &alphaBeta_g_tc;
                }

                alphaBeta_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                alphaBeta_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &alphaBeta_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqAdxl::alphaBeta>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqAdxl::alphaBeta>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqLwir::setOutput_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setOutput_req_g_tc_members[1]=
                {

                    {
                        (char *)"srefIxMsdcVSqrgrp",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setOutput_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqLwir::setOutput_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setOutput_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setOutput_req*/

                if (is_initialized) {
                    return &setOutput_req_g_tc;
                }

                setOutput_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<vecsref_AliasTag_t>::get().native();

                is_initialized = RTI_TRUE;

                return &setOutput_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqLwir::setOutput_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqLwir::setOutput_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqLwir::setOutput_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setOutput_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setOutput_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqLwir::setOutput_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setOutput_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setOutput_reply*/

                if (is_initialized) {
                    return &setOutput_reply_g_tc;
                }

                setOutput_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setOutput_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqLwir::setOutput_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqLwir::setOutput_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqLwir::start_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqLwir::start_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_req*/

                if (is_initialized) {
                    return &start_req_g_tc;
                }

                start_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqLwir::start_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqLwir::start_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqLwir::start_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqLwir::start_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_reply*/

                if (is_initialized) {
                    return &start_reply_g_tc;
                }

                start_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqLwir::start_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqLwir::start_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqLwir::stop_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqLwir::stop_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_req*/

                if (is_initialized) {
                    return &stop_req_g_tc;
                }

                stop_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqLwir::stop_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqLwir::stop_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqLwir::stop_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqLwir::stop_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_reply*/

                if (is_initialized) {
                    return &stop_reply_g_tc;
                }

                stop_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqLwir::stop_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqLwir::stop_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqLwir::seqnoTGray16> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode seqnoTGray16_g_tc_gray16_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((19200),NULL);
                static DDS_TypeCode_Member seqnoTGray16_g_tc_members[3]=
                {

                    {
                        (char *)"seqno",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"t",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"gray16",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode seqnoTGray16_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqLwir::seqnoTGray16", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        seqnoTGray16_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for seqnoTGray16*/

                if (is_initialized) {
                    return &seqnoTGray16_g_tc;
                }

                seqnoTGray16_g_tc_gray16_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

                seqnoTGray16_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<uint_AliasTag_t>::get().native();

                seqnoTGray16_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                seqnoTGray16_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& seqnoTGray16_g_tc_gray16_sequence;

                is_initialized = RTI_TRUE;

                return &seqnoTGray16_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqLwir::seqnoTGray16>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqLwir::seqnoTGray16>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::setFocus_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFocus_req_g_tc_members[1]=
                {

                    {
                        (char *)"focus",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setFocus_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::setFocus_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFocus_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setFocus_req*/

                if (is_initialized) {
                    return &setFocus_req_g_tc;
                }

                setFocus_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setFocus_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::setFocus_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::setFocus_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::setFocus_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFocus_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setFocus_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::setFocus_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFocus_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setFocus_reply*/

                if (is_initialized) {
                    return &setFocus_reply_g_tc;
                }

                setFocus_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setFocus_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::setFocus_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::setFocus_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::setOutput_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setOutput_req_g_tc_members[3]=
                {

                    {
                        (char *)"srefIxMsdcVCamres",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"srefIxMsdcVSqrgrp",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"grayscale",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setOutput_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::setOutput_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        setOutput_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setOutput_req*/

                if (is_initialized) {
                    return &setOutput_req_g_tc;
                }

                setOutput_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<vecsref_AliasTag_t>::get().native();

                setOutput_req_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<vecsref_AliasTag_t>::get().native();

                setOutput_req_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setOutput_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::setOutput_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::setOutput_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::setOutput_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setOutput_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setOutput_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::setOutput_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setOutput_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setOutput_reply*/

                if (is_initialized) {
                    return &setOutput_reply_g_tc;
                }

                setOutput_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setOutput_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::setOutput_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::setOutput_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::setTint_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setTint_req_g_tc_members[1]=
                {

                    {
                        (char *)"Tint",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setTint_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::setTint_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setTint_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setTint_req*/

                if (is_initialized) {
                    return &setTint_req_g_tc;
                }

                setTint_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setTint_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::setTint_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::setTint_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::setTint_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setTint_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setTint_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::setTint_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setTint_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setTint_reply*/

                if (is_initialized) {
                    return &setTint_reply_g_tc;
                }

                setTint_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setTint_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::setTint_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::setTint_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::start_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::start_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_req*/

                if (is_initialized) {
                    return &start_req_g_tc;
                }

                start_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::start_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::start_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::start_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::start_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_reply*/

                if (is_initialized) {
                    return &start_reply_g_tc;
                }

                start_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::start_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::start_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::stop_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::stop_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_req*/

                if (is_initialized) {
                    return &stop_req_g_tc;
                }

                stop_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::stop_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::stop_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::stop_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::stop_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_reply*/

                if (is_initialized) {
                    return &stop_reply_g_tc;
                }

                stop_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::stop_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::stop_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode seqnoTRgbx8Gray8_g_tc_rgbx8_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((4915200),NULL);
                static DDS_TypeCode seqnoTRgbx8Gray8_g_tc_gray8_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((1228800),NULL);
                static DDS_TypeCode_Member seqnoTRgbx8Gray8_g_tc_members[4]=
                {

                    {
                        (char *)"seqno",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"t",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"rgbx8",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"gray8",/* Member name */
                        {
                            3,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode seqnoTRgbx8Gray8_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        seqnoTRgbx8Gray8_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for seqnoTRgbx8Gray8*/

                if (is_initialized) {
                    return &seqnoTRgbx8Gray8_g_tc;
                }

                seqnoTRgbx8Gray8_g_tc_rgbx8_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                seqnoTRgbx8Gray8_g_tc_gray8_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                seqnoTRgbx8Gray8_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<uint_AliasTag_t>::get().native();

                seqnoTRgbx8Gray8_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                seqnoTRgbx8Gray8_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& seqnoTRgbx8Gray8_g_tc_rgbx8_sequence;
                seqnoTRgbx8Gray8_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& seqnoTRgbx8Gray8_g_tc_gray8_sequence;

                is_initialized = RTI_TRUE;

                return &seqnoTRgbx8Gray8_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::setFocus_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFocus_req_g_tc_members[1]=
                {

                    {
                        (char *)"focus",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setFocus_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::setFocus_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFocus_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setFocus_req*/

                if (is_initialized) {
                    return &setFocus_req_g_tc;
                }

                setFocus_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setFocus_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::setFocus_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::setFocus_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::setFocus_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFocus_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setFocus_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::setFocus_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFocus_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setFocus_reply*/

                if (is_initialized) {
                    return &setFocus_reply_g_tc;
                }

                setFocus_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setFocus_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::setFocus_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::setFocus_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::setOutput_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setOutput_req_g_tc_members[3]=
                {

                    {
                        (char *)"srefIxMsdcVCamres",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"srefIxMsdcVSqrgrp",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"grayscale",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setOutput_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::setOutput_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        setOutput_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setOutput_req*/

                if (is_initialized) {
                    return &setOutput_req_g_tc;
                }

                setOutput_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<vecsref_AliasTag_t>::get().native();

                setOutput_req_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<vecsref_AliasTag_t>::get().native();

                setOutput_req_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setOutput_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::setOutput_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::setOutput_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::setOutput_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setOutput_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setOutput_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::setOutput_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setOutput_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setOutput_reply*/

                if (is_initialized) {
                    return &setOutput_reply_g_tc;
                }

                setOutput_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setOutput_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::setOutput_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::setOutput_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::setTint_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setTint_req_g_tc_members[1]=
                {

                    {
                        (char *)"Tint",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setTint_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::setTint_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setTint_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setTint_req*/

                if (is_initialized) {
                    return &setTint_req_g_tc;
                }

                setTint_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setTint_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::setTint_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::setTint_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::setTint_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setTint_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setTint_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::setTint_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setTint_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setTint_reply*/

                if (is_initialized) {
                    return &setTint_reply_g_tc;
                }

                setTint_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setTint_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::setTint_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::setTint_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::start_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::start_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_req*/

                if (is_initialized) {
                    return &start_req_g_tc;
                }

                start_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::start_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::start_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::start_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::start_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_reply*/

                if (is_initialized) {
                    return &start_reply_g_tc;
                }

                start_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::start_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::start_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::stop_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::stop_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_req*/

                if (is_initialized) {
                    return &stop_req_g_tc;
                }

                stop_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::stop_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::stop_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::stop_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::stop_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_reply*/

                if (is_initialized) {
                    return &stop_reply_g_tc;
                }

                stop_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::stop_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::stop_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode seqnoTRgbx8Gray8_g_tc_rgbx8_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((4915200),NULL);
                static DDS_TypeCode seqnoTRgbx8Gray8_g_tc_gray8_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((1228800),NULL);
                static DDS_TypeCode_Member seqnoTRgbx8Gray8_g_tc_members[4]=
                {

                    {
                        (char *)"seqno",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"t",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"rgbx8",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"gray8",/* Member name */
                        {
                            3,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode seqnoTRgbx8Gray8_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        seqnoTRgbx8Gray8_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for seqnoTRgbx8Gray8*/

                if (is_initialized) {
                    return &seqnoTRgbx8Gray8_g_tc;
                }

                seqnoTRgbx8Gray8_g_tc_rgbx8_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                seqnoTRgbx8Gray8_g_tc_gray8_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                seqnoTRgbx8Gray8_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<uint_AliasTag_t>::get().native();

                seqnoTRgbx8Gray8_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                seqnoTRgbx8Gray8_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& seqnoTRgbx8Gray8_g_tc_rgbx8_sequence;
                seqnoTRgbx8Gray8_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& seqnoTRgbx8Gray8_g_tc_gray8_sequence;

                is_initialized = RTI_TRUE;

                return &seqnoTRgbx8Gray8_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActAlign::setWave_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode setWave_req_g_tc_seq_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((32),NULL);
                static DDS_TypeCode_Member setWave_req_g_tc_members[3]=
                {

                    {
                        (char *)"srefIxVFunction",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"N",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"seq",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setWave_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActAlign::setWave_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        setWave_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setWave_req*/

                if (is_initialized) {
                    return &setWave_req_g_tc;
                }

                setWave_req_g_tc_seq_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                setWave_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<vecsref_AliasTag_t>::get().native();

                setWave_req_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type<utinyint_AliasTag_t>::get().native();

                setWave_req_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& setWave_req_g_tc_seq_sequence;

                is_initialized = RTI_TRUE;

                return &setWave_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActAlign::setWave_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActAlign::setWave_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActAlign::setWave_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setWave_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setWave_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActAlign::setWave_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setWave_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setWave_reply*/

                if (is_initialized) {
                    return &setWave_reply_g_tc;
                }

                setWave_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setWave_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActAlign::setWave_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActAlign::setWave_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActAlign::start_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActAlign::start_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_req*/

                if (is_initialized) {
                    return &start_req_g_tc;
                }

                start_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActAlign::start_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActAlign::start_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActAlign::start_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member start_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode start_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActAlign::start_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        start_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for start_reply*/

                if (is_initialized) {
                    return &start_reply_g_tc;
                }

                start_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &start_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActAlign::start_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActAlign::start_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActAlign::stop_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActAlign::stop_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_req*/

                if (is_initialized) {
                    return &stop_req_g_tc;
                }

                stop_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActAlign::stop_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActAlign::stop_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActAlign::stop_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode stop_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActAlign::stop_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for stop_reply*/

                if (is_initialized) {
                    return &stop_reply_g_tc;
                }

                stop_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &stop_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActAlign::stop_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActAlign::stop_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActLed::setFlood_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFlood_req_g_tc_members[1]=
                {

                    {
                        (char *)"flood",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setFlood_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActLed::setFlood_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFlood_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setFlood_req*/

                if (is_initialized) {
                    return &setFlood_req_g_tc;
                }

                setFlood_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setFlood_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActLed::setFlood_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActLed::setFlood_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActLed::setFlood_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFlood_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setFlood_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActLed::setFlood_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFlood_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setFlood_reply*/

                if (is_initialized) {
                    return &setFlood_reply_g_tc;
                }

                setFlood_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setFlood_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActLed::setFlood_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActLed::setFlood_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActLed::setSpot_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setSpot_req_g_tc_members[1]=
                {

                    {
                        (char *)"spot",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setSpot_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActLed::setSpot_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setSpot_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setSpot_req*/

                if (is_initialized) {
                    return &setSpot_req_g_tc;
                }

                setSpot_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setSpot_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActLed::setSpot_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActLed::setSpot_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActLed::setSpot_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setSpot_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setSpot_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActLed::setSpot_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setSpot_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setSpot_reply*/

                if (is_initialized) {
                    return &setSpot_reply_g_tc;
                }

                setSpot_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setSpot_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActLed::setSpot_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActLed::setSpot_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActLed::floodSpot> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member floodSpot_g_tc_members[2]=
                {

                    {
                        (char *)"flood",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"spot",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode floodSpot_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActLed::floodSpot", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        floodSpot_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for floodSpot*/

                if (is_initialized) {
                    return &floodSpot_g_tc;
                }

                floodSpot_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                floodSpot_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &floodSpot_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActLed::floodSpot>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActLed::floodSpot>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActServo::setPhi_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setPhi_req_g_tc_members[1]=
                {

                    {
                        (char *)"phi",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setPhi_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActServo::setPhi_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setPhi_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setPhi_req*/

                if (is_initialized) {
                    return &setPhi_req_g_tc;
                }

                setPhi_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setPhi_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActServo::setPhi_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActServo::setPhi_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActServo::setPhi_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setPhi_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setPhi_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActServo::setPhi_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setPhi_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setPhi_reply*/

                if (is_initialized) {
                    return &setPhi_reply_g_tc;
                }

                setPhi_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setPhi_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActServo::setPhi_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActServo::setPhi_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActServo::setTheta_req> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setTheta_req_g_tc_members[1]=
                {

                    {
                        (char *)"theta",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setTheta_req_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActServo::setTheta_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setTheta_req_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setTheta_req*/

                if (is_initialized) {
                    return &setTheta_req_g_tc;
                }

                setTheta_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &setTheta_req_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActServo::setTheta_req>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActServo::setTheta_req>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActServo::setTheta_reply> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setTheta_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode setTheta_reply_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActServo::setTheta_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setTheta_reply_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for setTheta_reply*/

                if (is_initialized) {
                    return &setTheta_reply_g_tc;
                }

                setTheta_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                is_initialized = RTI_TRUE;

                return &setTheta_reply_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActServo::setTheta_reply>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActServo::setTheta_reply>::get())));
        }

        template<>
        struct native_type_code<DdsJobMsdcActServo::thetaPhi> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member thetaPhi_g_tc_members[2]=
                {

                    {
                        (char *)"theta",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"phi",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode thetaPhi_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobMsdcActServo::thetaPhi", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        thetaPhi_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for thetaPhi*/

                if (is_initialized) {
                    return &thetaPhi_g_tc;
                }

                thetaPhi_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                thetaPhi_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &thetaPhi_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DdsJobMsdcActServo::thetaPhi>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DdsJobMsdcActServo::thetaPhi>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<DdsJobMsdcAcqAdxl::alphaBeta>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqAdxl::alphaBetaPlugin_new,
                DdsJobMsdcAcqAdxl::alphaBetaPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqAdxl::alphaBeta>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqAdxl::alphaBeta& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = alphaBetaPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = alphaBetaPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqAdxl::alphaBeta>::from_cdr_buffer(DdsJobMsdcAcqAdxl::alphaBeta& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = alphaBetaPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqAdxl::alphaBeta from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqAdxl::alphaBeta>::reset_sample(DdsJobMsdcAcqAdxl::alphaBeta& sample) 
        {
            rti::topic::reset_sample(sample.alpha());
            rti::topic::reset_sample(sample.beta());
        }

        void topic_type_support<DdsJobMsdcAcqAdxl::alphaBeta>::allocate_sample(DdsJobMsdcAcqAdxl::alphaBeta& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqLwir::setOutput_reqPlugin_new,
                DdsJobMsdcAcqLwir::setOutput_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqLwir::setOutput_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqLwir::setOutput_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setOutput_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setOutput_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_req>::from_cdr_buffer(DdsJobMsdcAcqLwir::setOutput_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setOutput_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqLwir::setOutput_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_req>::reset_sample(DdsJobMsdcAcqLwir::setOutput_req& sample) 
        {
            rti::topic::reset_sample(sample.srefIxMsdcVSqrgrp());
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_req>::allocate_sample(DdsJobMsdcAcqLwir::setOutput_req& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.srefIxMsdcVSqrgrp(),  -1, 50);
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqLwir::setOutput_replyPlugin_new,
                DdsJobMsdcAcqLwir::setOutput_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqLwir::setOutput_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqLwir::setOutput_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setOutput_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setOutput_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_reply>::from_cdr_buffer(DdsJobMsdcAcqLwir::setOutput_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setOutput_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqLwir::setOutput_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_reply>::reset_sample(DdsJobMsdcAcqLwir::setOutput_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqLwir::setOutput_reply>::allocate_sample(DdsJobMsdcAcqLwir::setOutput_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqLwir::start_reqPlugin_new,
                DdsJobMsdcAcqLwir::start_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqLwir::start_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqLwir::start_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_req>::from_cdr_buffer(DdsJobMsdcAcqLwir::start_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqLwir::start_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_req>::reset_sample(DdsJobMsdcAcqLwir::start_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_req>::allocate_sample(DdsJobMsdcAcqLwir::start_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqLwir::start_replyPlugin_new,
                DdsJobMsdcAcqLwir::start_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqLwir::start_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqLwir::start_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_reply>::from_cdr_buffer(DdsJobMsdcAcqLwir::start_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqLwir::start_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_reply>::reset_sample(DdsJobMsdcAcqLwir::start_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqLwir::start_reply>::allocate_sample(DdsJobMsdcAcqLwir::start_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqLwir::stop_reqPlugin_new,
                DdsJobMsdcAcqLwir::stop_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqLwir::stop_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqLwir::stop_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_req>::from_cdr_buffer(DdsJobMsdcAcqLwir::stop_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqLwir::stop_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_req>::reset_sample(DdsJobMsdcAcqLwir::stop_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_req>::allocate_sample(DdsJobMsdcAcqLwir::stop_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqLwir::stop_replyPlugin_new,
                DdsJobMsdcAcqLwir::stop_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqLwir::stop_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqLwir::stop_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_reply>::from_cdr_buffer(DdsJobMsdcAcqLwir::stop_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqLwir::stop_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_reply>::reset_sample(DdsJobMsdcAcqLwir::stop_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqLwir::stop_reply>::allocate_sample(DdsJobMsdcAcqLwir::stop_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqLwir::seqnoTGray16>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqLwir::seqnoTGray16Plugin_new,
                DdsJobMsdcAcqLwir::seqnoTGray16Plugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqLwir::seqnoTGray16>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqLwir::seqnoTGray16& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = seqnoTGray16Plugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = seqnoTGray16Plugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqLwir::seqnoTGray16>::from_cdr_buffer(DdsJobMsdcAcqLwir::seqnoTGray16& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = seqnoTGray16Plugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqLwir::seqnoTGray16 from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqLwir::seqnoTGray16>::reset_sample(DdsJobMsdcAcqLwir::seqnoTGray16& sample) 
        {
            rti::topic::reset_sample(sample.seqno());
            rti::topic::reset_sample(sample.t());
            rti::topic::reset_sample(sample.gray16());
        }

        void topic_type_support<DdsJobMsdcAcqLwir::seqnoTGray16>::allocate_sample(DdsJobMsdcAcqLwir::seqnoTGray16& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.seqno(),  -1, -1);
            rti::topic::allocate_sample(sample.gray16(),  19200, -1);
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::setFocus_reqPlugin_new,
                DdsJobMsdcAcqVisl::setFocus_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::setFocus_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setFocus_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFocus_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFocus_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_req>::from_cdr_buffer(DdsJobMsdcAcqVisl::setFocus_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFocus_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::setFocus_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_req>::reset_sample(DdsJobMsdcAcqVisl::setFocus_req& sample) 
        {
            rti::topic::reset_sample(sample.focus());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_req>::allocate_sample(DdsJobMsdcAcqVisl::setFocus_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::setFocus_replyPlugin_new,
                DdsJobMsdcAcqVisl::setFocus_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::setFocus_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setFocus_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFocus_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFocus_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_reply>::from_cdr_buffer(DdsJobMsdcAcqVisl::setFocus_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFocus_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::setFocus_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_reply>::reset_sample(DdsJobMsdcAcqVisl::setFocus_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setFocus_reply>::allocate_sample(DdsJobMsdcAcqVisl::setFocus_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::setOutput_reqPlugin_new,
                DdsJobMsdcAcqVisl::setOutput_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::setOutput_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setOutput_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setOutput_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setOutput_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_req>::from_cdr_buffer(DdsJobMsdcAcqVisl::setOutput_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setOutput_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::setOutput_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_req>::reset_sample(DdsJobMsdcAcqVisl::setOutput_req& sample) 
        {
            rti::topic::reset_sample(sample.srefIxMsdcVCamres());
            rti::topic::reset_sample(sample.srefIxMsdcVSqrgrp());
            rti::topic::reset_sample(sample.grayscale());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_req>::allocate_sample(DdsJobMsdcAcqVisl::setOutput_req& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.srefIxMsdcVCamres(),  -1, 50);
            rti::topic::allocate_sample(sample.srefIxMsdcVSqrgrp(),  -1, 50);
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::setOutput_replyPlugin_new,
                DdsJobMsdcAcqVisl::setOutput_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::setOutput_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setOutput_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setOutput_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setOutput_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_reply>::from_cdr_buffer(DdsJobMsdcAcqVisl::setOutput_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setOutput_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::setOutput_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_reply>::reset_sample(DdsJobMsdcAcqVisl::setOutput_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setOutput_reply>::allocate_sample(DdsJobMsdcAcqVisl::setOutput_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::setTint_reqPlugin_new,
                DdsJobMsdcAcqVisl::setTint_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::setTint_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setTint_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setTint_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setTint_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_req>::from_cdr_buffer(DdsJobMsdcAcqVisl::setTint_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setTint_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::setTint_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_req>::reset_sample(DdsJobMsdcAcqVisl::setTint_req& sample) 
        {
            rti::topic::reset_sample(sample.Tint());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_req>::allocate_sample(DdsJobMsdcAcqVisl::setTint_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::setTint_replyPlugin_new,
                DdsJobMsdcAcqVisl::setTint_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::setTint_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setTint_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setTint_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setTint_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_reply>::from_cdr_buffer(DdsJobMsdcAcqVisl::setTint_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setTint_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::setTint_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_reply>::reset_sample(DdsJobMsdcAcqVisl::setTint_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::setTint_reply>::allocate_sample(DdsJobMsdcAcqVisl::setTint_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::start_reqPlugin_new,
                DdsJobMsdcAcqVisl::start_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::start_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::start_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_req>::from_cdr_buffer(DdsJobMsdcAcqVisl::start_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::start_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_req>::reset_sample(DdsJobMsdcAcqVisl::start_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_req>::allocate_sample(DdsJobMsdcAcqVisl::start_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::start_replyPlugin_new,
                DdsJobMsdcAcqVisl::start_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::start_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::start_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_reply>::from_cdr_buffer(DdsJobMsdcAcqVisl::start_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::start_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_reply>::reset_sample(DdsJobMsdcAcqVisl::start_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::start_reply>::allocate_sample(DdsJobMsdcAcqVisl::start_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::stop_reqPlugin_new,
                DdsJobMsdcAcqVisl::stop_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::stop_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::stop_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_req>::from_cdr_buffer(DdsJobMsdcAcqVisl::stop_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::stop_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_req>::reset_sample(DdsJobMsdcAcqVisl::stop_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_req>::allocate_sample(DdsJobMsdcAcqVisl::stop_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::stop_replyPlugin_new,
                DdsJobMsdcAcqVisl::stop_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::stop_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::stop_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_reply>::from_cdr_buffer(DdsJobMsdcAcqVisl::stop_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::stop_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_reply>::reset_sample(DdsJobMsdcAcqVisl::stop_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::stop_reply>::allocate_sample(DdsJobMsdcAcqVisl::stop_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8Plugin_new,
                DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8Plugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = seqnoTRgbx8Gray8Plugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = seqnoTRgbx8Gray8Plugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>::from_cdr_buffer(DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = seqnoTRgbx8Gray8Plugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8 from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>::reset_sample(DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample) 
        {
            rti::topic::reset_sample(sample.seqno());
            rti::topic::reset_sample(sample.t());
            rti::topic::reset_sample(sample.rgbx8());
            rti::topic::reset_sample(sample.gray8());
        }

        void topic_type_support<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>::allocate_sample(DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.seqno(),  -1, -1);
            rti::topic::allocate_sample(sample.rgbx8(),  4915200, -1);
            rti::topic::allocate_sample(sample.gray8(),  1228800, -1);
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::setFocus_reqPlugin_new,
                DdsJobMsdcAcqVisr::setFocus_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::setFocus_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setFocus_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFocus_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFocus_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_req>::from_cdr_buffer(DdsJobMsdcAcqVisr::setFocus_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFocus_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::setFocus_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_req>::reset_sample(DdsJobMsdcAcqVisr::setFocus_req& sample) 
        {
            rti::topic::reset_sample(sample.focus());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_req>::allocate_sample(DdsJobMsdcAcqVisr::setFocus_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::setFocus_replyPlugin_new,
                DdsJobMsdcAcqVisr::setFocus_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::setFocus_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setFocus_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFocus_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFocus_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_reply>::from_cdr_buffer(DdsJobMsdcAcqVisr::setFocus_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFocus_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::setFocus_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_reply>::reset_sample(DdsJobMsdcAcqVisr::setFocus_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setFocus_reply>::allocate_sample(DdsJobMsdcAcqVisr::setFocus_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::setOutput_reqPlugin_new,
                DdsJobMsdcAcqVisr::setOutput_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::setOutput_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setOutput_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setOutput_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setOutput_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_req>::from_cdr_buffer(DdsJobMsdcAcqVisr::setOutput_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setOutput_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::setOutput_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_req>::reset_sample(DdsJobMsdcAcqVisr::setOutput_req& sample) 
        {
            rti::topic::reset_sample(sample.srefIxMsdcVCamres());
            rti::topic::reset_sample(sample.srefIxMsdcVSqrgrp());
            rti::topic::reset_sample(sample.grayscale());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_req>::allocate_sample(DdsJobMsdcAcqVisr::setOutput_req& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.srefIxMsdcVCamres(),  -1, 50);
            rti::topic::allocate_sample(sample.srefIxMsdcVSqrgrp(),  -1, 50);
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::setOutput_replyPlugin_new,
                DdsJobMsdcAcqVisr::setOutput_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::setOutput_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setOutput_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setOutput_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setOutput_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_reply>::from_cdr_buffer(DdsJobMsdcAcqVisr::setOutput_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setOutput_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::setOutput_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_reply>::reset_sample(DdsJobMsdcAcqVisr::setOutput_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setOutput_reply>::allocate_sample(DdsJobMsdcAcqVisr::setOutput_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::setTint_reqPlugin_new,
                DdsJobMsdcAcqVisr::setTint_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::setTint_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setTint_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setTint_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setTint_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_req>::from_cdr_buffer(DdsJobMsdcAcqVisr::setTint_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setTint_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::setTint_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_req>::reset_sample(DdsJobMsdcAcqVisr::setTint_req& sample) 
        {
            rti::topic::reset_sample(sample.Tint());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_req>::allocate_sample(DdsJobMsdcAcqVisr::setTint_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::setTint_replyPlugin_new,
                DdsJobMsdcAcqVisr::setTint_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::setTint_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setTint_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setTint_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setTint_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_reply>::from_cdr_buffer(DdsJobMsdcAcqVisr::setTint_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setTint_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::setTint_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_reply>::reset_sample(DdsJobMsdcAcqVisr::setTint_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::setTint_reply>::allocate_sample(DdsJobMsdcAcqVisr::setTint_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::start_reqPlugin_new,
                DdsJobMsdcAcqVisr::start_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::start_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::start_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_req>::from_cdr_buffer(DdsJobMsdcAcqVisr::start_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::start_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_req>::reset_sample(DdsJobMsdcAcqVisr::start_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_req>::allocate_sample(DdsJobMsdcAcqVisr::start_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::start_replyPlugin_new,
                DdsJobMsdcAcqVisr::start_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::start_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::start_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_reply>::from_cdr_buffer(DdsJobMsdcAcqVisr::start_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::start_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_reply>::reset_sample(DdsJobMsdcAcqVisr::start_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::start_reply>::allocate_sample(DdsJobMsdcAcqVisr::start_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::stop_reqPlugin_new,
                DdsJobMsdcAcqVisr::stop_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::stop_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::stop_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_req>::from_cdr_buffer(DdsJobMsdcAcqVisr::stop_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::stop_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_req>::reset_sample(DdsJobMsdcAcqVisr::stop_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_req>::allocate_sample(DdsJobMsdcAcqVisr::stop_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::stop_replyPlugin_new,
                DdsJobMsdcAcqVisr::stop_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::stop_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::stop_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_reply>::from_cdr_buffer(DdsJobMsdcAcqVisr::stop_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::stop_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_reply>::reset_sample(DdsJobMsdcAcqVisr::stop_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::stop_reply>::allocate_sample(DdsJobMsdcAcqVisr::stop_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8Plugin_new,
                DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8Plugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = seqnoTRgbx8Gray8Plugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = seqnoTRgbx8Gray8Plugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>::from_cdr_buffer(DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = seqnoTRgbx8Gray8Plugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8 from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>::reset_sample(DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample) 
        {
            rti::topic::reset_sample(sample.seqno());
            rti::topic::reset_sample(sample.t());
            rti::topic::reset_sample(sample.rgbx8());
            rti::topic::reset_sample(sample.gray8());
        }

        void topic_type_support<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>::allocate_sample(DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.seqno(),  -1, -1);
            rti::topic::allocate_sample(sample.rgbx8(),  4915200, -1);
            rti::topic::allocate_sample(sample.gray8(),  1228800, -1);
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActAlign::setWave_reqPlugin_new,
                DdsJobMsdcActAlign::setWave_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActAlign::setWave_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActAlign::setWave_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setWave_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setWave_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_req>::from_cdr_buffer(DdsJobMsdcActAlign::setWave_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setWave_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActAlign::setWave_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_req>::reset_sample(DdsJobMsdcActAlign::setWave_req& sample) 
        {
            rti::topic::reset_sample(sample.srefIxVFunction());
            rti::topic::reset_sample(sample.N());
            rti::topic::reset_sample(sample.seq());
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_req>::allocate_sample(DdsJobMsdcActAlign::setWave_req& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.srefIxVFunction(),  -1, 50);
            rti::topic::allocate_sample(sample.N(),  -1, -1);
            rti::topic::allocate_sample(sample.seq(),  32, -1);
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActAlign::setWave_replyPlugin_new,
                DdsJobMsdcActAlign::setWave_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActAlign::setWave_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActAlign::setWave_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setWave_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setWave_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_reply>::from_cdr_buffer(DdsJobMsdcActAlign::setWave_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setWave_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActAlign::setWave_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_reply>::reset_sample(DdsJobMsdcActAlign::setWave_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcActAlign::setWave_reply>::allocate_sample(DdsJobMsdcActAlign::setWave_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActAlign::start_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActAlign::start_reqPlugin_new,
                DdsJobMsdcActAlign::start_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActAlign::start_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActAlign::start_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActAlign::start_req>::from_cdr_buffer(DdsJobMsdcActAlign::start_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActAlign::start_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActAlign::start_req>::reset_sample(DdsJobMsdcActAlign::start_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcActAlign::start_req>::allocate_sample(DdsJobMsdcActAlign::start_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActAlign::start_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActAlign::start_replyPlugin_new,
                DdsJobMsdcActAlign::start_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActAlign::start_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActAlign::start_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = start_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = start_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActAlign::start_reply>::from_cdr_buffer(DdsJobMsdcActAlign::start_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = start_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActAlign::start_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActAlign::start_reply>::reset_sample(DdsJobMsdcActAlign::start_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcActAlign::start_reply>::allocate_sample(DdsJobMsdcActAlign::start_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActAlign::stop_reqPlugin_new,
                DdsJobMsdcActAlign::stop_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActAlign::stop_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActAlign::stop_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_req>::from_cdr_buffer(DdsJobMsdcActAlign::stop_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActAlign::stop_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_req>::reset_sample(DdsJobMsdcActAlign::stop_req& sample) 
        {
            rti::topic::reset_sample(sample.dummy());
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_req>::allocate_sample(DdsJobMsdcActAlign::stop_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActAlign::stop_replyPlugin_new,
                DdsJobMsdcActAlign::stop_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActAlign::stop_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActAlign::stop_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_reply>::from_cdr_buffer(DdsJobMsdcActAlign::stop_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActAlign::stop_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_reply>::reset_sample(DdsJobMsdcActAlign::stop_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcActAlign::stop_reply>::allocate_sample(DdsJobMsdcActAlign::stop_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActLed::setFlood_reqPlugin_new,
                DdsJobMsdcActLed::setFlood_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActLed::setFlood_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActLed::setFlood_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFlood_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFlood_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_req>::from_cdr_buffer(DdsJobMsdcActLed::setFlood_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFlood_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActLed::setFlood_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_req>::reset_sample(DdsJobMsdcActLed::setFlood_req& sample) 
        {
            rti::topic::reset_sample(sample.flood());
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_req>::allocate_sample(DdsJobMsdcActLed::setFlood_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActLed::setFlood_replyPlugin_new,
                DdsJobMsdcActLed::setFlood_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActLed::setFlood_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActLed::setFlood_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFlood_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFlood_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_reply>::from_cdr_buffer(DdsJobMsdcActLed::setFlood_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFlood_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActLed::setFlood_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_reply>::reset_sample(DdsJobMsdcActLed::setFlood_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcActLed::setFlood_reply>::allocate_sample(DdsJobMsdcActLed::setFlood_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActLed::setSpot_reqPlugin_new,
                DdsJobMsdcActLed::setSpot_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActLed::setSpot_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActLed::setSpot_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setSpot_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setSpot_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_req>::from_cdr_buffer(DdsJobMsdcActLed::setSpot_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setSpot_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActLed::setSpot_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_req>::reset_sample(DdsJobMsdcActLed::setSpot_req& sample) 
        {
            rti::topic::reset_sample(sample.spot());
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_req>::allocate_sample(DdsJobMsdcActLed::setSpot_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActLed::setSpot_replyPlugin_new,
                DdsJobMsdcActLed::setSpot_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActLed::setSpot_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActLed::setSpot_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setSpot_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setSpot_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_reply>::from_cdr_buffer(DdsJobMsdcActLed::setSpot_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setSpot_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActLed::setSpot_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_reply>::reset_sample(DdsJobMsdcActLed::setSpot_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcActLed::setSpot_reply>::allocate_sample(DdsJobMsdcActLed::setSpot_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActLed::floodSpot>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActLed::floodSpotPlugin_new,
                DdsJobMsdcActLed::floodSpotPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActLed::floodSpot>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActLed::floodSpot& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = floodSpotPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = floodSpotPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActLed::floodSpot>::from_cdr_buffer(DdsJobMsdcActLed::floodSpot& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = floodSpotPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActLed::floodSpot from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActLed::floodSpot>::reset_sample(DdsJobMsdcActLed::floodSpot& sample) 
        {
            rti::topic::reset_sample(sample.flood());
            rti::topic::reset_sample(sample.spot());
        }

        void topic_type_support<DdsJobMsdcActLed::floodSpot>::allocate_sample(DdsJobMsdcActLed::floodSpot& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActServo::setPhi_reqPlugin_new,
                DdsJobMsdcActServo::setPhi_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActServo::setPhi_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActServo::setPhi_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setPhi_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setPhi_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_req>::from_cdr_buffer(DdsJobMsdcActServo::setPhi_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setPhi_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActServo::setPhi_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_req>::reset_sample(DdsJobMsdcActServo::setPhi_req& sample) 
        {
            rti::topic::reset_sample(sample.phi());
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_req>::allocate_sample(DdsJobMsdcActServo::setPhi_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActServo::setPhi_replyPlugin_new,
                DdsJobMsdcActServo::setPhi_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActServo::setPhi_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActServo::setPhi_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setPhi_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setPhi_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_reply>::from_cdr_buffer(DdsJobMsdcActServo::setPhi_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setPhi_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActServo::setPhi_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_reply>::reset_sample(DdsJobMsdcActServo::setPhi_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcActServo::setPhi_reply>::allocate_sample(DdsJobMsdcActServo::setPhi_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_req>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActServo::setTheta_reqPlugin_new,
                DdsJobMsdcActServo::setTheta_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActServo::setTheta_req>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActServo::setTheta_req& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setTheta_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setTheta_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_req>::from_cdr_buffer(DdsJobMsdcActServo::setTheta_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setTheta_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActServo::setTheta_req from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_req>::reset_sample(DdsJobMsdcActServo::setTheta_req& sample) 
        {
            rti::topic::reset_sample(sample.theta());
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_req>::allocate_sample(DdsJobMsdcActServo::setTheta_req& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_reply>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActServo::setTheta_replyPlugin_new,
                DdsJobMsdcActServo::setTheta_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActServo::setTheta_reply>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActServo::setTheta_reply& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setTheta_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setTheta_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_reply>::from_cdr_buffer(DdsJobMsdcActServo::setTheta_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setTheta_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActServo::setTheta_reply from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_reply>::reset_sample(DdsJobMsdcActServo::setTheta_reply& sample) 
        {
            rti::topic::reset_sample(sample.success());
        }

        void topic_type_support<DdsJobMsdcActServo::setTheta_reply>::allocate_sample(DdsJobMsdcActServo::setTheta_reply& sample, int, int) 
        {
        }

        void topic_type_support<DdsJobMsdcActServo::thetaPhi>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobMsdcActServo::thetaPhiPlugin_new,
                DdsJobMsdcActServo::thetaPhiPlugin_delete);
        }

        std::vector<char>& topic_type_support<DdsJobMsdcActServo::thetaPhi>::to_cdr_buffer(
            std::vector<char>& buffer, const DdsJobMsdcActServo::thetaPhi& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = thetaPhiPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = thetaPhiPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DdsJobMsdcActServo::thetaPhi>::from_cdr_buffer(DdsJobMsdcActServo::thetaPhi& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = thetaPhiPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobMsdcActServo::thetaPhi from cdr buffer");
        }

        void topic_type_support<DdsJobMsdcActServo::thetaPhi>::reset_sample(DdsJobMsdcActServo::thetaPhi& sample) 
        {
            rti::topic::reset_sample(sample.theta());
            rti::topic::reset_sample(sample.phi());
        }

        void topic_type_support<DdsJobMsdcActServo::thetaPhi>::allocate_sample(DdsJobMsdcActServo::thetaPhi& sample, int, int) 
        {
        }

    }
}  

