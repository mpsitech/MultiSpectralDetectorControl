

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DdsMsdc.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef DdsMsdc_1182983940_hpp
#define DdsMsdc_1182983940_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

typedef char tinyint;
struct tinyint_AliasTag_t {};

typedef uint8_t utinyint;
struct utinyint_AliasTag_t {};

typedef int16_t smallint;
struct smallint_AliasTag_t {};

typedef uint16_t usmallint;
struct usmallint_AliasTag_t {};

typedef int32_t _cxx_int;
struct _cxx_int_AliasTag_t {};

typedef uint32_t uint;
struct uint_AliasTag_t {};

typedef rti::core::int64 bigint;
struct bigint_AliasTag_t {};

typedef rti::core::uint64 ubigint;
struct ubigint_AliasTag_t {};

typedef std::string vecsref;
struct vecsref_AliasTag_t {};
namespace DdsJobMsdcAcqAdxl {

    class NDDSUSERDllExport alphaBeta {

      public:
        alphaBeta();

        alphaBeta(
            float alpha,
            float beta);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        alphaBeta (alphaBeta&&) = default;
        alphaBeta& operator=(alphaBeta&&) = default;
        alphaBeta& operator=(const alphaBeta&) = default;
        alphaBeta(const alphaBeta&) = default;
        #else
        alphaBeta(alphaBeta&& other_) OMG_NOEXCEPT;  
        alphaBeta& operator=(alphaBeta&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& alpha() OMG_NOEXCEPT; 
        const float& alpha() const OMG_NOEXCEPT;
        void alpha(float value);

        float& beta() OMG_NOEXCEPT; 
        const float& beta() const OMG_NOEXCEPT;
        void beta(float value);

        bool operator == (const alphaBeta& other_) const;
        bool operator != (const alphaBeta& other_) const;

        void swap(alphaBeta& other_) OMG_NOEXCEPT ;

      private:

        float m_alpha_;
        float m_beta_;

    };

    inline void swap(alphaBeta& a, alphaBeta& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const alphaBeta& sample);

} // namespace DdsJobMsdcAcqAdxl  
namespace DdsJobMsdcAcqLwir {

    class NDDSUSERDllExport setOutput_req {

      public:
        setOutput_req();

        explicit setOutput_req(
            const vecsref& ixMsdcVSqrgrp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setOutput_req (setOutput_req&&) = default;
        setOutput_req& operator=(setOutput_req&&) = default;
        setOutput_req& operator=(const setOutput_req&) = default;
        setOutput_req(const setOutput_req&) = default;
        #else
        setOutput_req(setOutput_req&& other_) OMG_NOEXCEPT;  
        setOutput_req& operator=(setOutput_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        vecsref& ixMsdcVSqrgrp() OMG_NOEXCEPT; 
        const vecsref& ixMsdcVSqrgrp() const OMG_NOEXCEPT;
        void ixMsdcVSqrgrp(const vecsref& value);

        bool operator == (const setOutput_req& other_) const;
        bool operator != (const setOutput_req& other_) const;

        void swap(setOutput_req& other_) OMG_NOEXCEPT ;

      private:

        vecsref m_ixMsdcVSqrgrp_;

    };

    inline void swap(setOutput_req& a, setOutput_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setOutput_req& sample);

    class NDDSUSERDllExport setOutput_reply {

      public:
        setOutput_reply();

        explicit setOutput_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setOutput_reply (setOutput_reply&&) = default;
        setOutput_reply& operator=(setOutput_reply&&) = default;
        setOutput_reply& operator=(const setOutput_reply&) = default;
        setOutput_reply(const setOutput_reply&) = default;
        #else
        setOutput_reply(setOutput_reply&& other_) OMG_NOEXCEPT;  
        setOutput_reply& operator=(setOutput_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setOutput_reply& other_) const;
        bool operator != (const setOutput_reply& other_) const;

        void swap(setOutput_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setOutput_reply& a, setOutput_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setOutput_reply& sample);

    class NDDSUSERDllExport start_req {

      public:
        start_req();

        explicit start_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_req (start_req&&) = default;
        start_req& operator=(start_req&&) = default;
        start_req& operator=(const start_req&) = default;
        start_req(const start_req&) = default;
        #else
        start_req(start_req&& other_) OMG_NOEXCEPT;  
        start_req& operator=(start_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const start_req& other_) const;
        bool operator != (const start_req& other_) const;

        void swap(start_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(start_req& a, start_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_req& sample);

    class NDDSUSERDllExport start_reply {

      public:
        start_reply();

        explicit start_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_reply (start_reply&&) = default;
        start_reply& operator=(start_reply&&) = default;
        start_reply& operator=(const start_reply&) = default;
        start_reply(const start_reply&) = default;
        #else
        start_reply(start_reply&& other_) OMG_NOEXCEPT;  
        start_reply& operator=(start_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const start_reply& other_) const;
        bool operator != (const start_reply& other_) const;

        void swap(start_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(start_reply& a, start_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_reply& sample);

    class NDDSUSERDllExport stop_req {

      public:
        stop_req();

        explicit stop_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_req (stop_req&&) = default;
        stop_req& operator=(stop_req&&) = default;
        stop_req& operator=(const stop_req&) = default;
        stop_req(const stop_req&) = default;
        #else
        stop_req(stop_req&& other_) OMG_NOEXCEPT;  
        stop_req& operator=(stop_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const stop_req& other_) const;
        bool operator != (const stop_req& other_) const;

        void swap(stop_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(stop_req& a, stop_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_req& sample);

    class NDDSUSERDllExport stop_reply {

      public:
        stop_reply();

        explicit stop_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_reply (stop_reply&&) = default;
        stop_reply& operator=(stop_reply&&) = default;
        stop_reply& operator=(const stop_reply&) = default;
        stop_reply(const stop_reply&) = default;
        #else
        stop_reply(stop_reply&& other_) OMG_NOEXCEPT;  
        stop_reply& operator=(stop_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const stop_reply& other_) const;
        bool operator != (const stop_reply& other_) const;

        void swap(stop_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(stop_reply& a, stop_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_reply& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator<uint16_t>;
    template class NDDSUSERDllExport std::vector<uint16_t >;
    #endif
    class NDDSUSERDllExport seqnoTGray16 {

      public:
        seqnoTGray16();

        seqnoTGray16(
            const uint& seqno,
            double t,
            const rti::core::bounded_sequence<uint16_t, 19200>& gray16);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        seqnoTGray16 (seqnoTGray16&&) = default;
        seqnoTGray16& operator=(seqnoTGray16&&) = default;
        seqnoTGray16& operator=(const seqnoTGray16&) = default;
        seqnoTGray16(const seqnoTGray16&) = default;
        #else
        seqnoTGray16(seqnoTGray16&& other_) OMG_NOEXCEPT;  
        seqnoTGray16& operator=(seqnoTGray16&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint& seqno() OMG_NOEXCEPT; 
        const uint& seqno() const OMG_NOEXCEPT;
        void seqno(const uint& value);

        double& t() OMG_NOEXCEPT; 
        const double& t() const OMG_NOEXCEPT;
        void t(double value);

        rti::core::bounded_sequence<uint16_t, 19200>& gray16() OMG_NOEXCEPT; 
        const rti::core::bounded_sequence<uint16_t, 19200>& gray16() const OMG_NOEXCEPT;
        void gray16(const rti::core::bounded_sequence<uint16_t, 19200>& value);

        bool operator == (const seqnoTGray16& other_) const;
        bool operator != (const seqnoTGray16& other_) const;

        void swap(seqnoTGray16& other_) OMG_NOEXCEPT ;

      private:

        uint m_seqno_;
        double m_t_;
        rti::core::bounded_sequence<uint16_t, 19200> m_gray16_;

    };

    inline void swap(seqnoTGray16& a, seqnoTGray16& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const seqnoTGray16& sample);

} // namespace DdsJobMsdcAcqLwir  
namespace DdsJobMsdcAcqVisl {

    class NDDSUSERDllExport setFocus_req {

      public:
        setFocus_req();

        explicit setFocus_req(
            float focus);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFocus_req (setFocus_req&&) = default;
        setFocus_req& operator=(setFocus_req&&) = default;
        setFocus_req& operator=(const setFocus_req&) = default;
        setFocus_req(const setFocus_req&) = default;
        #else
        setFocus_req(setFocus_req&& other_) OMG_NOEXCEPT;  
        setFocus_req& operator=(setFocus_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& focus() OMG_NOEXCEPT; 
        const float& focus() const OMG_NOEXCEPT;
        void focus(float value);

        bool operator == (const setFocus_req& other_) const;
        bool operator != (const setFocus_req& other_) const;

        void swap(setFocus_req& other_) OMG_NOEXCEPT ;

      private:

        float m_focus_;

    };

    inline void swap(setFocus_req& a, setFocus_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFocus_req& sample);

    class NDDSUSERDllExport setFocus_reply {

      public:
        setFocus_reply();

        explicit setFocus_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFocus_reply (setFocus_reply&&) = default;
        setFocus_reply& operator=(setFocus_reply&&) = default;
        setFocus_reply& operator=(const setFocus_reply&) = default;
        setFocus_reply(const setFocus_reply&) = default;
        #else
        setFocus_reply(setFocus_reply&& other_) OMG_NOEXCEPT;  
        setFocus_reply& operator=(setFocus_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setFocus_reply& other_) const;
        bool operator != (const setFocus_reply& other_) const;

        void swap(setFocus_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setFocus_reply& a, setFocus_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFocus_reply& sample);

    class NDDSUSERDllExport setOutput_req {

      public:
        setOutput_req();

        setOutput_req(
            const vecsref& ixMsdcVCamres,
            const vecsref& ixMsdcVSqrgrp,
            bool grayscale);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setOutput_req (setOutput_req&&) = default;
        setOutput_req& operator=(setOutput_req&&) = default;
        setOutput_req& operator=(const setOutput_req&) = default;
        setOutput_req(const setOutput_req&) = default;
        #else
        setOutput_req(setOutput_req&& other_) OMG_NOEXCEPT;  
        setOutput_req& operator=(setOutput_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        vecsref& ixMsdcVCamres() OMG_NOEXCEPT; 
        const vecsref& ixMsdcVCamres() const OMG_NOEXCEPT;
        void ixMsdcVCamres(const vecsref& value);

        vecsref& ixMsdcVSqrgrp() OMG_NOEXCEPT; 
        const vecsref& ixMsdcVSqrgrp() const OMG_NOEXCEPT;
        void ixMsdcVSqrgrp(const vecsref& value);

        bool& grayscale() OMG_NOEXCEPT; 
        const bool& grayscale() const OMG_NOEXCEPT;
        void grayscale(bool value);

        bool operator == (const setOutput_req& other_) const;
        bool operator != (const setOutput_req& other_) const;

        void swap(setOutput_req& other_) OMG_NOEXCEPT ;

      private:

        vecsref m_ixMsdcVCamres_;
        vecsref m_ixMsdcVSqrgrp_;
        bool m_grayscale_;

    };

    inline void swap(setOutput_req& a, setOutput_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setOutput_req& sample);

    class NDDSUSERDllExport setOutput_reply {

      public:
        setOutput_reply();

        explicit setOutput_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setOutput_reply (setOutput_reply&&) = default;
        setOutput_reply& operator=(setOutput_reply&&) = default;
        setOutput_reply& operator=(const setOutput_reply&) = default;
        setOutput_reply(const setOutput_reply&) = default;
        #else
        setOutput_reply(setOutput_reply&& other_) OMG_NOEXCEPT;  
        setOutput_reply& operator=(setOutput_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setOutput_reply& other_) const;
        bool operator != (const setOutput_reply& other_) const;

        void swap(setOutput_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setOutput_reply& a, setOutput_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setOutput_reply& sample);

    class NDDSUSERDllExport setTint_req {

      public:
        setTint_req();

        explicit setTint_req(
            float Tint);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setTint_req (setTint_req&&) = default;
        setTint_req& operator=(setTint_req&&) = default;
        setTint_req& operator=(const setTint_req&) = default;
        setTint_req(const setTint_req&) = default;
        #else
        setTint_req(setTint_req&& other_) OMG_NOEXCEPT;  
        setTint_req& operator=(setTint_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& Tint() OMG_NOEXCEPT; 
        const float& Tint() const OMG_NOEXCEPT;
        void Tint(float value);

        bool operator == (const setTint_req& other_) const;
        bool operator != (const setTint_req& other_) const;

        void swap(setTint_req& other_) OMG_NOEXCEPT ;

      private:

        float m_Tint_;

    };

    inline void swap(setTint_req& a, setTint_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setTint_req& sample);

    class NDDSUSERDllExport setTint_reply {

      public:
        setTint_reply();

        explicit setTint_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setTint_reply (setTint_reply&&) = default;
        setTint_reply& operator=(setTint_reply&&) = default;
        setTint_reply& operator=(const setTint_reply&) = default;
        setTint_reply(const setTint_reply&) = default;
        #else
        setTint_reply(setTint_reply&& other_) OMG_NOEXCEPT;  
        setTint_reply& operator=(setTint_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setTint_reply& other_) const;
        bool operator != (const setTint_reply& other_) const;

        void swap(setTint_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setTint_reply& a, setTint_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setTint_reply& sample);

    class NDDSUSERDllExport start_req {

      public:
        start_req();

        explicit start_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_req (start_req&&) = default;
        start_req& operator=(start_req&&) = default;
        start_req& operator=(const start_req&) = default;
        start_req(const start_req&) = default;
        #else
        start_req(start_req&& other_) OMG_NOEXCEPT;  
        start_req& operator=(start_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const start_req& other_) const;
        bool operator != (const start_req& other_) const;

        void swap(start_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(start_req& a, start_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_req& sample);

    class NDDSUSERDllExport start_reply {

      public:
        start_reply();

        explicit start_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_reply (start_reply&&) = default;
        start_reply& operator=(start_reply&&) = default;
        start_reply& operator=(const start_reply&) = default;
        start_reply(const start_reply&) = default;
        #else
        start_reply(start_reply&& other_) OMG_NOEXCEPT;  
        start_reply& operator=(start_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const start_reply& other_) const;
        bool operator != (const start_reply& other_) const;

        void swap(start_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(start_reply& a, start_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_reply& sample);

    class NDDSUSERDllExport stop_req {

      public:
        stop_req();

        explicit stop_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_req (stop_req&&) = default;
        stop_req& operator=(stop_req&&) = default;
        stop_req& operator=(const stop_req&) = default;
        stop_req(const stop_req&) = default;
        #else
        stop_req(stop_req&& other_) OMG_NOEXCEPT;  
        stop_req& operator=(stop_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const stop_req& other_) const;
        bool operator != (const stop_req& other_) const;

        void swap(stop_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(stop_req& a, stop_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_req& sample);

    class NDDSUSERDllExport stop_reply {

      public:
        stop_reply();

        explicit stop_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_reply (stop_reply&&) = default;
        stop_reply& operator=(stop_reply&&) = default;
        stop_reply& operator=(const stop_reply&) = default;
        stop_reply(const stop_reply&) = default;
        #else
        stop_reply(stop_reply&& other_) OMG_NOEXCEPT;  
        stop_reply& operator=(stop_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const stop_reply& other_) const;
        bool operator != (const stop_reply& other_) const;

        void swap(stop_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(stop_reply& a, stop_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_reply& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator<uint8_t>;
    template class NDDSUSERDllExport std::vector<uint8_t >;
    #endif
    class NDDSUSERDllExport seqnoTRgbx8Gray8 {

      public:
        seqnoTRgbx8Gray8();

        seqnoTRgbx8Gray8(
            const uint& seqno,
            double t,
            const rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8,
            const rti::core::bounded_sequence<uint8_t, 1228800>& gray8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        seqnoTRgbx8Gray8 (seqnoTRgbx8Gray8&&) = default;
        seqnoTRgbx8Gray8& operator=(seqnoTRgbx8Gray8&&) = default;
        seqnoTRgbx8Gray8& operator=(const seqnoTRgbx8Gray8&) = default;
        seqnoTRgbx8Gray8(const seqnoTRgbx8Gray8&) = default;
        #else
        seqnoTRgbx8Gray8(seqnoTRgbx8Gray8&& other_) OMG_NOEXCEPT;  
        seqnoTRgbx8Gray8& operator=(seqnoTRgbx8Gray8&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint& seqno() OMG_NOEXCEPT; 
        const uint& seqno() const OMG_NOEXCEPT;
        void seqno(const uint& value);

        double& t() OMG_NOEXCEPT; 
        const double& t() const OMG_NOEXCEPT;
        void t(double value);

        rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8() OMG_NOEXCEPT; 
        const rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8() const OMG_NOEXCEPT;
        void rgbx8(const rti::core::bounded_sequence<uint8_t, 4915200>& value);

        rti::core::bounded_sequence<uint8_t, 1228800>& gray8() OMG_NOEXCEPT; 
        const rti::core::bounded_sequence<uint8_t, 1228800>& gray8() const OMG_NOEXCEPT;
        void gray8(const rti::core::bounded_sequence<uint8_t, 1228800>& value);

        bool operator == (const seqnoTRgbx8Gray8& other_) const;
        bool operator != (const seqnoTRgbx8Gray8& other_) const;

        void swap(seqnoTRgbx8Gray8& other_) OMG_NOEXCEPT ;

      private:

        uint m_seqno_;
        double m_t_;
        rti::core::bounded_sequence<uint8_t, 4915200> m_rgbx8_;
        rti::core::bounded_sequence<uint8_t, 1228800> m_gray8_;

    };

    inline void swap(seqnoTRgbx8Gray8& a, seqnoTRgbx8Gray8& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const seqnoTRgbx8Gray8& sample);

} // namespace DdsJobMsdcAcqVisl  
namespace DdsJobMsdcAcqVisr {

    class NDDSUSERDllExport setFocus_req {

      public:
        setFocus_req();

        explicit setFocus_req(
            float focus);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFocus_req (setFocus_req&&) = default;
        setFocus_req& operator=(setFocus_req&&) = default;
        setFocus_req& operator=(const setFocus_req&) = default;
        setFocus_req(const setFocus_req&) = default;
        #else
        setFocus_req(setFocus_req&& other_) OMG_NOEXCEPT;  
        setFocus_req& operator=(setFocus_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& focus() OMG_NOEXCEPT; 
        const float& focus() const OMG_NOEXCEPT;
        void focus(float value);

        bool operator == (const setFocus_req& other_) const;
        bool operator != (const setFocus_req& other_) const;

        void swap(setFocus_req& other_) OMG_NOEXCEPT ;

      private:

        float m_focus_;

    };

    inline void swap(setFocus_req& a, setFocus_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFocus_req& sample);

    class NDDSUSERDllExport setFocus_reply {

      public:
        setFocus_reply();

        explicit setFocus_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFocus_reply (setFocus_reply&&) = default;
        setFocus_reply& operator=(setFocus_reply&&) = default;
        setFocus_reply& operator=(const setFocus_reply&) = default;
        setFocus_reply(const setFocus_reply&) = default;
        #else
        setFocus_reply(setFocus_reply&& other_) OMG_NOEXCEPT;  
        setFocus_reply& operator=(setFocus_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setFocus_reply& other_) const;
        bool operator != (const setFocus_reply& other_) const;

        void swap(setFocus_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setFocus_reply& a, setFocus_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFocus_reply& sample);

    class NDDSUSERDllExport setOutput_req {

      public:
        setOutput_req();

        setOutput_req(
            const vecsref& ixMsdcVCamres,
            const vecsref& ixMsdcVSqrgrp,
            bool grayscale);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setOutput_req (setOutput_req&&) = default;
        setOutput_req& operator=(setOutput_req&&) = default;
        setOutput_req& operator=(const setOutput_req&) = default;
        setOutput_req(const setOutput_req&) = default;
        #else
        setOutput_req(setOutput_req&& other_) OMG_NOEXCEPT;  
        setOutput_req& operator=(setOutput_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        vecsref& ixMsdcVCamres() OMG_NOEXCEPT; 
        const vecsref& ixMsdcVCamres() const OMG_NOEXCEPT;
        void ixMsdcVCamres(const vecsref& value);

        vecsref& ixMsdcVSqrgrp() OMG_NOEXCEPT; 
        const vecsref& ixMsdcVSqrgrp() const OMG_NOEXCEPT;
        void ixMsdcVSqrgrp(const vecsref& value);

        bool& grayscale() OMG_NOEXCEPT; 
        const bool& grayscale() const OMG_NOEXCEPT;
        void grayscale(bool value);

        bool operator == (const setOutput_req& other_) const;
        bool operator != (const setOutput_req& other_) const;

        void swap(setOutput_req& other_) OMG_NOEXCEPT ;

      private:

        vecsref m_ixMsdcVCamres_;
        vecsref m_ixMsdcVSqrgrp_;
        bool m_grayscale_;

    };

    inline void swap(setOutput_req& a, setOutput_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setOutput_req& sample);

    class NDDSUSERDllExport setOutput_reply {

      public:
        setOutput_reply();

        explicit setOutput_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setOutput_reply (setOutput_reply&&) = default;
        setOutput_reply& operator=(setOutput_reply&&) = default;
        setOutput_reply& operator=(const setOutput_reply&) = default;
        setOutput_reply(const setOutput_reply&) = default;
        #else
        setOutput_reply(setOutput_reply&& other_) OMG_NOEXCEPT;  
        setOutput_reply& operator=(setOutput_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setOutput_reply& other_) const;
        bool operator != (const setOutput_reply& other_) const;

        void swap(setOutput_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setOutput_reply& a, setOutput_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setOutput_reply& sample);

    class NDDSUSERDllExport setTint_req {

      public:
        setTint_req();

        explicit setTint_req(
            float Tint);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setTint_req (setTint_req&&) = default;
        setTint_req& operator=(setTint_req&&) = default;
        setTint_req& operator=(const setTint_req&) = default;
        setTint_req(const setTint_req&) = default;
        #else
        setTint_req(setTint_req&& other_) OMG_NOEXCEPT;  
        setTint_req& operator=(setTint_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& Tint() OMG_NOEXCEPT; 
        const float& Tint() const OMG_NOEXCEPT;
        void Tint(float value);

        bool operator == (const setTint_req& other_) const;
        bool operator != (const setTint_req& other_) const;

        void swap(setTint_req& other_) OMG_NOEXCEPT ;

      private:

        float m_Tint_;

    };

    inline void swap(setTint_req& a, setTint_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setTint_req& sample);

    class NDDSUSERDllExport setTint_reply {

      public:
        setTint_reply();

        explicit setTint_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setTint_reply (setTint_reply&&) = default;
        setTint_reply& operator=(setTint_reply&&) = default;
        setTint_reply& operator=(const setTint_reply&) = default;
        setTint_reply(const setTint_reply&) = default;
        #else
        setTint_reply(setTint_reply&& other_) OMG_NOEXCEPT;  
        setTint_reply& operator=(setTint_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setTint_reply& other_) const;
        bool operator != (const setTint_reply& other_) const;

        void swap(setTint_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setTint_reply& a, setTint_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setTint_reply& sample);

    class NDDSUSERDllExport start_req {

      public:
        start_req();

        explicit start_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_req (start_req&&) = default;
        start_req& operator=(start_req&&) = default;
        start_req& operator=(const start_req&) = default;
        start_req(const start_req&) = default;
        #else
        start_req(start_req&& other_) OMG_NOEXCEPT;  
        start_req& operator=(start_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const start_req& other_) const;
        bool operator != (const start_req& other_) const;

        void swap(start_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(start_req& a, start_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_req& sample);

    class NDDSUSERDllExport start_reply {

      public:
        start_reply();

        explicit start_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_reply (start_reply&&) = default;
        start_reply& operator=(start_reply&&) = default;
        start_reply& operator=(const start_reply&) = default;
        start_reply(const start_reply&) = default;
        #else
        start_reply(start_reply&& other_) OMG_NOEXCEPT;  
        start_reply& operator=(start_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const start_reply& other_) const;
        bool operator != (const start_reply& other_) const;

        void swap(start_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(start_reply& a, start_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_reply& sample);

    class NDDSUSERDllExport stop_req {

      public:
        stop_req();

        explicit stop_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_req (stop_req&&) = default;
        stop_req& operator=(stop_req&&) = default;
        stop_req& operator=(const stop_req&) = default;
        stop_req(const stop_req&) = default;
        #else
        stop_req(stop_req&& other_) OMG_NOEXCEPT;  
        stop_req& operator=(stop_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const stop_req& other_) const;
        bool operator != (const stop_req& other_) const;

        void swap(stop_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(stop_req& a, stop_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_req& sample);

    class NDDSUSERDllExport stop_reply {

      public:
        stop_reply();

        explicit stop_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_reply (stop_reply&&) = default;
        stop_reply& operator=(stop_reply&&) = default;
        stop_reply& operator=(const stop_reply&) = default;
        stop_reply(const stop_reply&) = default;
        #else
        stop_reply(stop_reply&& other_) OMG_NOEXCEPT;  
        stop_reply& operator=(stop_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const stop_reply& other_) const;
        bool operator != (const stop_reply& other_) const;

        void swap(stop_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(stop_reply& a, stop_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_reply& sample);

    class NDDSUSERDllExport seqnoTRgbx8Gray8 {

      public:
        seqnoTRgbx8Gray8();

        seqnoTRgbx8Gray8(
            const uint& seqno,
            double t,
            const rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8,
            const rti::core::bounded_sequence<uint8_t, 1228800>& gray8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        seqnoTRgbx8Gray8 (seqnoTRgbx8Gray8&&) = default;
        seqnoTRgbx8Gray8& operator=(seqnoTRgbx8Gray8&&) = default;
        seqnoTRgbx8Gray8& operator=(const seqnoTRgbx8Gray8&) = default;
        seqnoTRgbx8Gray8(const seqnoTRgbx8Gray8&) = default;
        #else
        seqnoTRgbx8Gray8(seqnoTRgbx8Gray8&& other_) OMG_NOEXCEPT;  
        seqnoTRgbx8Gray8& operator=(seqnoTRgbx8Gray8&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint& seqno() OMG_NOEXCEPT; 
        const uint& seqno() const OMG_NOEXCEPT;
        void seqno(const uint& value);

        double& t() OMG_NOEXCEPT; 
        const double& t() const OMG_NOEXCEPT;
        void t(double value);

        rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8() OMG_NOEXCEPT; 
        const rti::core::bounded_sequence<uint8_t, 4915200>& rgbx8() const OMG_NOEXCEPT;
        void rgbx8(const rti::core::bounded_sequence<uint8_t, 4915200>& value);

        rti::core::bounded_sequence<uint8_t, 1228800>& gray8() OMG_NOEXCEPT; 
        const rti::core::bounded_sequence<uint8_t, 1228800>& gray8() const OMG_NOEXCEPT;
        void gray8(const rti::core::bounded_sequence<uint8_t, 1228800>& value);

        bool operator == (const seqnoTRgbx8Gray8& other_) const;
        bool operator != (const seqnoTRgbx8Gray8& other_) const;

        void swap(seqnoTRgbx8Gray8& other_) OMG_NOEXCEPT ;

      private:

        uint m_seqno_;
        double m_t_;
        rti::core::bounded_sequence<uint8_t, 4915200> m_rgbx8_;
        rti::core::bounded_sequence<uint8_t, 1228800> m_gray8_;

    };

    inline void swap(seqnoTRgbx8Gray8& a, seqnoTRgbx8Gray8& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const seqnoTRgbx8Gray8& sample);

} // namespace DdsJobMsdcAcqVisr  
namespace DdsJobMsdcActAlign {

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator<float>;
    template class NDDSUSERDllExport std::vector<float >;
    #endif
    class NDDSUSERDllExport setWave_req {

      public:
        setWave_req();

        setWave_req(
            const vecsref& ixVFunction,
            const utinyint& N,
            const rti::core::bounded_sequence<float, 32>& seq);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setWave_req (setWave_req&&) = default;
        setWave_req& operator=(setWave_req&&) = default;
        setWave_req& operator=(const setWave_req&) = default;
        setWave_req(const setWave_req&) = default;
        #else
        setWave_req(setWave_req&& other_) OMG_NOEXCEPT;  
        setWave_req& operator=(setWave_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        vecsref& ixVFunction() OMG_NOEXCEPT; 
        const vecsref& ixVFunction() const OMG_NOEXCEPT;
        void ixVFunction(const vecsref& value);

        utinyint& N() OMG_NOEXCEPT; 
        const utinyint& N() const OMG_NOEXCEPT;
        void N(const utinyint& value);

        rti::core::bounded_sequence<float, 32>& seq() OMG_NOEXCEPT; 
        const rti::core::bounded_sequence<float, 32>& seq() const OMG_NOEXCEPT;
        void seq(const rti::core::bounded_sequence<float, 32>& value);

        bool operator == (const setWave_req& other_) const;
        bool operator != (const setWave_req& other_) const;

        void swap(setWave_req& other_) OMG_NOEXCEPT ;

      private:

        vecsref m_ixVFunction_;
        utinyint m_N_;
        rti::core::bounded_sequence<float, 32> m_seq_;

    };

    inline void swap(setWave_req& a, setWave_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setWave_req& sample);

    class NDDSUSERDllExport setWave_reply {

      public:
        setWave_reply();

        explicit setWave_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setWave_reply (setWave_reply&&) = default;
        setWave_reply& operator=(setWave_reply&&) = default;
        setWave_reply& operator=(const setWave_reply&) = default;
        setWave_reply(const setWave_reply&) = default;
        #else
        setWave_reply(setWave_reply&& other_) OMG_NOEXCEPT;  
        setWave_reply& operator=(setWave_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setWave_reply& other_) const;
        bool operator != (const setWave_reply& other_) const;

        void swap(setWave_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setWave_reply& a, setWave_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setWave_reply& sample);

    class NDDSUSERDllExport start_req {

      public:
        start_req();

        explicit start_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_req (start_req&&) = default;
        start_req& operator=(start_req&&) = default;
        start_req& operator=(const start_req&) = default;
        start_req(const start_req&) = default;
        #else
        start_req(start_req&& other_) OMG_NOEXCEPT;  
        start_req& operator=(start_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const start_req& other_) const;
        bool operator != (const start_req& other_) const;

        void swap(start_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(start_req& a, start_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_req& sample);

    class NDDSUSERDllExport start_reply {

      public:
        start_reply();

        explicit start_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        start_reply (start_reply&&) = default;
        start_reply& operator=(start_reply&&) = default;
        start_reply& operator=(const start_reply&) = default;
        start_reply(const start_reply&) = default;
        #else
        start_reply(start_reply&& other_) OMG_NOEXCEPT;  
        start_reply& operator=(start_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const start_reply& other_) const;
        bool operator != (const start_reply& other_) const;

        void swap(start_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(start_reply& a, start_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const start_reply& sample);

    class NDDSUSERDllExport stop_req {

      public:
        stop_req();

        explicit stop_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_req (stop_req&&) = default;
        stop_req& operator=(stop_req&&) = default;
        stop_req& operator=(const stop_req&) = default;
        stop_req(const stop_req&) = default;
        #else
        stop_req(stop_req&& other_) OMG_NOEXCEPT;  
        stop_req& operator=(stop_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT; 
        const bool& dummy() const OMG_NOEXCEPT;
        void dummy(bool value);

        bool operator == (const stop_req& other_) const;
        bool operator != (const stop_req& other_) const;

        void swap(stop_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(stop_req& a, stop_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_req& sample);

    class NDDSUSERDllExport stop_reply {

      public:
        stop_reply();

        explicit stop_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_reply (stop_reply&&) = default;
        stop_reply& operator=(stop_reply&&) = default;
        stop_reply& operator=(const stop_reply&) = default;
        stop_reply(const stop_reply&) = default;
        #else
        stop_reply(stop_reply&& other_) OMG_NOEXCEPT;  
        stop_reply& operator=(stop_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const stop_reply& other_) const;
        bool operator != (const stop_reply& other_) const;

        void swap(stop_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(stop_reply& a, stop_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_reply& sample);

} // namespace DdsJobMsdcActAlign  
namespace DdsJobMsdcActLed {

    class NDDSUSERDllExport setFlood_req {

      public:
        setFlood_req();

        explicit setFlood_req(
            float flood);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFlood_req (setFlood_req&&) = default;
        setFlood_req& operator=(setFlood_req&&) = default;
        setFlood_req& operator=(const setFlood_req&) = default;
        setFlood_req(const setFlood_req&) = default;
        #else
        setFlood_req(setFlood_req&& other_) OMG_NOEXCEPT;  
        setFlood_req& operator=(setFlood_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& flood() OMG_NOEXCEPT; 
        const float& flood() const OMG_NOEXCEPT;
        void flood(float value);

        bool operator == (const setFlood_req& other_) const;
        bool operator != (const setFlood_req& other_) const;

        void swap(setFlood_req& other_) OMG_NOEXCEPT ;

      private:

        float m_flood_;

    };

    inline void swap(setFlood_req& a, setFlood_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFlood_req& sample);

    class NDDSUSERDllExport setFlood_reply {

      public:
        setFlood_reply();

        explicit setFlood_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFlood_reply (setFlood_reply&&) = default;
        setFlood_reply& operator=(setFlood_reply&&) = default;
        setFlood_reply& operator=(const setFlood_reply&) = default;
        setFlood_reply(const setFlood_reply&) = default;
        #else
        setFlood_reply(setFlood_reply&& other_) OMG_NOEXCEPT;  
        setFlood_reply& operator=(setFlood_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setFlood_reply& other_) const;
        bool operator != (const setFlood_reply& other_) const;

        void swap(setFlood_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setFlood_reply& a, setFlood_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFlood_reply& sample);

    class NDDSUSERDllExport setSpot_req {

      public:
        setSpot_req();

        explicit setSpot_req(
            float spot);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setSpot_req (setSpot_req&&) = default;
        setSpot_req& operator=(setSpot_req&&) = default;
        setSpot_req& operator=(const setSpot_req&) = default;
        setSpot_req(const setSpot_req&) = default;
        #else
        setSpot_req(setSpot_req&& other_) OMG_NOEXCEPT;  
        setSpot_req& operator=(setSpot_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& spot() OMG_NOEXCEPT; 
        const float& spot() const OMG_NOEXCEPT;
        void spot(float value);

        bool operator == (const setSpot_req& other_) const;
        bool operator != (const setSpot_req& other_) const;

        void swap(setSpot_req& other_) OMG_NOEXCEPT ;

      private:

        float m_spot_;

    };

    inline void swap(setSpot_req& a, setSpot_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setSpot_req& sample);

    class NDDSUSERDllExport setSpot_reply {

      public:
        setSpot_reply();

        explicit setSpot_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setSpot_reply (setSpot_reply&&) = default;
        setSpot_reply& operator=(setSpot_reply&&) = default;
        setSpot_reply& operator=(const setSpot_reply&) = default;
        setSpot_reply(const setSpot_reply&) = default;
        #else
        setSpot_reply(setSpot_reply&& other_) OMG_NOEXCEPT;  
        setSpot_reply& operator=(setSpot_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setSpot_reply& other_) const;
        bool operator != (const setSpot_reply& other_) const;

        void swap(setSpot_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setSpot_reply& a, setSpot_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setSpot_reply& sample);

    class NDDSUSERDllExport floodSpot {

      public:
        floodSpot();

        floodSpot(
            float flood,
            float spot);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        floodSpot (floodSpot&&) = default;
        floodSpot& operator=(floodSpot&&) = default;
        floodSpot& operator=(const floodSpot&) = default;
        floodSpot(const floodSpot&) = default;
        #else
        floodSpot(floodSpot&& other_) OMG_NOEXCEPT;  
        floodSpot& operator=(floodSpot&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& flood() OMG_NOEXCEPT; 
        const float& flood() const OMG_NOEXCEPT;
        void flood(float value);

        float& spot() OMG_NOEXCEPT; 
        const float& spot() const OMG_NOEXCEPT;
        void spot(float value);

        bool operator == (const floodSpot& other_) const;
        bool operator != (const floodSpot& other_) const;

        void swap(floodSpot& other_) OMG_NOEXCEPT ;

      private:

        float m_flood_;
        float m_spot_;

    };

    inline void swap(floodSpot& a, floodSpot& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const floodSpot& sample);

} // namespace DdsJobMsdcActLed  
namespace DdsJobMsdcActServo {

    class NDDSUSERDllExport setPhi_req {

      public:
        setPhi_req();

        explicit setPhi_req(
            float phi);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setPhi_req (setPhi_req&&) = default;
        setPhi_req& operator=(setPhi_req&&) = default;
        setPhi_req& operator=(const setPhi_req&) = default;
        setPhi_req(const setPhi_req&) = default;
        #else
        setPhi_req(setPhi_req&& other_) OMG_NOEXCEPT;  
        setPhi_req& operator=(setPhi_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& phi() OMG_NOEXCEPT; 
        const float& phi() const OMG_NOEXCEPT;
        void phi(float value);

        bool operator == (const setPhi_req& other_) const;
        bool operator != (const setPhi_req& other_) const;

        void swap(setPhi_req& other_) OMG_NOEXCEPT ;

      private:

        float m_phi_;

    };

    inline void swap(setPhi_req& a, setPhi_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setPhi_req& sample);

    class NDDSUSERDllExport setPhi_reply {

      public:
        setPhi_reply();

        explicit setPhi_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setPhi_reply (setPhi_reply&&) = default;
        setPhi_reply& operator=(setPhi_reply&&) = default;
        setPhi_reply& operator=(const setPhi_reply&) = default;
        setPhi_reply(const setPhi_reply&) = default;
        #else
        setPhi_reply(setPhi_reply&& other_) OMG_NOEXCEPT;  
        setPhi_reply& operator=(setPhi_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setPhi_reply& other_) const;
        bool operator != (const setPhi_reply& other_) const;

        void swap(setPhi_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setPhi_reply& a, setPhi_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setPhi_reply& sample);

    class NDDSUSERDllExport setTheta_req {

      public:
        setTheta_req();

        explicit setTheta_req(
            float theta);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setTheta_req (setTheta_req&&) = default;
        setTheta_req& operator=(setTheta_req&&) = default;
        setTheta_req& operator=(const setTheta_req&) = default;
        setTheta_req(const setTheta_req&) = default;
        #else
        setTheta_req(setTheta_req&& other_) OMG_NOEXCEPT;  
        setTheta_req& operator=(setTheta_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& theta() OMG_NOEXCEPT; 
        const float& theta() const OMG_NOEXCEPT;
        void theta(float value);

        bool operator == (const setTheta_req& other_) const;
        bool operator != (const setTheta_req& other_) const;

        void swap(setTheta_req& other_) OMG_NOEXCEPT ;

      private:

        float m_theta_;

    };

    inline void swap(setTheta_req& a, setTheta_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setTheta_req& sample);

    class NDDSUSERDllExport setTheta_reply {

      public:
        setTheta_reply();

        explicit setTheta_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setTheta_reply (setTheta_reply&&) = default;
        setTheta_reply& operator=(setTheta_reply&&) = default;
        setTheta_reply& operator=(const setTheta_reply&) = default;
        setTheta_reply(const setTheta_reply&) = default;
        #else
        setTheta_reply(setTheta_reply&& other_) OMG_NOEXCEPT;  
        setTheta_reply& operator=(setTheta_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT; 
        const bool& success() const OMG_NOEXCEPT;
        void success(bool value);

        bool operator == (const setTheta_reply& other_) const;
        bool operator != (const setTheta_reply& other_) const;

        void swap(setTheta_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setTheta_reply& a, setTheta_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setTheta_reply& sample);

    class NDDSUSERDllExport thetaPhi {

      public:
        thetaPhi();

        thetaPhi(
            float theta,
            float phi);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        thetaPhi (thetaPhi&&) = default;
        thetaPhi& operator=(thetaPhi&&) = default;
        thetaPhi& operator=(const thetaPhi&) = default;
        thetaPhi(const thetaPhi&) = default;
        #else
        thetaPhi(thetaPhi&& other_) OMG_NOEXCEPT;  
        thetaPhi& operator=(thetaPhi&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& theta() OMG_NOEXCEPT; 
        const float& theta() const OMG_NOEXCEPT;
        void theta(float value);

        float& phi() OMG_NOEXCEPT; 
        const float& phi() const OMG_NOEXCEPT;
        void phi(float value);

        bool operator == (const thetaPhi& other_) const;
        bool operator != (const thetaPhi& other_) const;

        void swap(thetaPhi& other_) OMG_NOEXCEPT ;

      private:

        float m_theta_;
        float m_phi_;

    };

    inline void swap(thetaPhi& a, thetaPhi& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const thetaPhi& sample);

} // namespace DdsJobMsdcActServo  
namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<DdsJobMsdcAcqAdxl::alphaBeta> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqAdxl::alphaBeta";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqAdxl::alphaBeta> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqAdxl::alphaBeta> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqAdxl::alphaBeta& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqAdxl::alphaBeta& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqAdxl::alphaBeta& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqAdxl::alphaBeta& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqLwir::setOutput_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqLwir::setOutput_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqLwir::setOutput_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqLwir::setOutput_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqLwir::setOutput_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqLwir::setOutput_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqLwir::setOutput_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqLwir::setOutput_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqLwir::setOutput_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqLwir::setOutput_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqLwir::setOutput_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqLwir::setOutput_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqLwir::setOutput_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqLwir::setOutput_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqLwir::setOutput_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqLwir::setOutput_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqLwir::start_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqLwir::start_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqLwir::start_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqLwir::start_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqLwir::start_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqLwir::start_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqLwir::start_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqLwir::start_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqLwir::start_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqLwir::start_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqLwir::start_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqLwir::start_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqLwir::start_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqLwir::start_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqLwir::start_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqLwir::start_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqLwir::stop_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqLwir::stop_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqLwir::stop_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqLwir::stop_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqLwir::stop_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqLwir::stop_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqLwir::stop_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqLwir::stop_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqLwir::stop_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqLwir::stop_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqLwir::stop_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqLwir::stop_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqLwir::stop_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqLwir::stop_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqLwir::stop_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqLwir::stop_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqLwir::seqnoTGray16> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqLwir::seqnoTGray16";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqLwir::seqnoTGray16> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqLwir::seqnoTGray16> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqLwir::seqnoTGray16& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqLwir::seqnoTGray16& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqLwir::seqnoTGray16& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqLwir::seqnoTGray16& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::setFocus_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::setFocus_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::setFocus_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::setFocus_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setFocus_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::setFocus_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::setFocus_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::setFocus_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::setFocus_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::setFocus_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::setFocus_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::setFocus_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setFocus_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::setFocus_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::setFocus_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::setFocus_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::setOutput_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::setOutput_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::setOutput_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::setOutput_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setOutput_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::setOutput_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::setOutput_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::setOutput_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::setOutput_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::setOutput_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::setOutput_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::setOutput_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setOutput_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::setOutput_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::setOutput_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::setOutput_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::setTint_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::setTint_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::setTint_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::setTint_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setTint_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::setTint_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::setTint_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::setTint_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::setTint_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::setTint_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::setTint_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::setTint_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::setTint_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::setTint_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::setTint_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::setTint_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::start_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::start_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::start_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::start_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::start_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::start_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::start_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::start_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::start_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::start_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::start_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::start_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::start_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::start_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::start_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::start_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::stop_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::stop_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::stop_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::stop_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::stop_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::stop_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::stop_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::stop_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::stop_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::stop_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::stop_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::stop_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::stop_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::stop_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::stop_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::stop_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::setFocus_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::setFocus_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::setFocus_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::setFocus_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setFocus_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::setFocus_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::setFocus_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::setFocus_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::setFocus_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::setFocus_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::setFocus_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::setFocus_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setFocus_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::setFocus_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::setFocus_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::setFocus_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::setOutput_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::setOutput_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::setOutput_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::setOutput_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setOutput_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::setOutput_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::setOutput_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::setOutput_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::setOutput_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::setOutput_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::setOutput_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::setOutput_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setOutput_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::setOutput_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::setOutput_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::setOutput_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::setTint_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::setTint_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::setTint_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::setTint_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setTint_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::setTint_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::setTint_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::setTint_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::setTint_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::setTint_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::setTint_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::setTint_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::setTint_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::setTint_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::setTint_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::setTint_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::start_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::start_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::start_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::start_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::start_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::start_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::start_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::start_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::start_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::start_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::start_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::start_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::start_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::start_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::start_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::start_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::stop_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::stop_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::stop_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::stop_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::stop_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::stop_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::stop_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::stop_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::stop_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::stop_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::stop_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::stop_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::stop_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::stop_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::stop_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::stop_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActAlign::setWave_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActAlign::setWave_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActAlign::setWave_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActAlign::setWave_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActAlign::setWave_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActAlign::setWave_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActAlign::setWave_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActAlign::setWave_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActAlign::setWave_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActAlign::setWave_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActAlign::setWave_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActAlign::setWave_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActAlign::setWave_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActAlign::setWave_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActAlign::setWave_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActAlign::setWave_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActAlign::start_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActAlign::start_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActAlign::start_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActAlign::start_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActAlign::start_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActAlign::start_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActAlign::start_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActAlign::start_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActAlign::start_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActAlign::start_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActAlign::start_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActAlign::start_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActAlign::start_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActAlign::start_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActAlign::start_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActAlign::start_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActAlign::stop_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActAlign::stop_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActAlign::stop_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActAlign::stop_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActAlign::stop_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActAlign::stop_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActAlign::stop_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActAlign::stop_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActAlign::stop_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActAlign::stop_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActAlign::stop_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActAlign::stop_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActAlign::stop_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActAlign::stop_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActAlign::stop_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActAlign::stop_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActLed::setFlood_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActLed::setFlood_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActLed::setFlood_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActLed::setFlood_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActLed::setFlood_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActLed::setFlood_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActLed::setFlood_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActLed::setFlood_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActLed::setFlood_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActLed::setFlood_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActLed::setFlood_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActLed::setFlood_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActLed::setFlood_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActLed::setFlood_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActLed::setFlood_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActLed::setFlood_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActLed::setSpot_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActLed::setSpot_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActLed::setSpot_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActLed::setSpot_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActLed::setSpot_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActLed::setSpot_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActLed::setSpot_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActLed::setSpot_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActLed::setSpot_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActLed::setSpot_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActLed::setSpot_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActLed::setSpot_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActLed::setSpot_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActLed::setSpot_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActLed::setSpot_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActLed::setSpot_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActLed::floodSpot> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActLed::floodSpot";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActLed::floodSpot> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActLed::floodSpot> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActLed::floodSpot& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActLed::floodSpot& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActLed::floodSpot& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActLed::floodSpot& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActServo::setPhi_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActServo::setPhi_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActServo::setPhi_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActServo::setPhi_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActServo::setPhi_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActServo::setPhi_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActServo::setPhi_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActServo::setPhi_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActServo::setPhi_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActServo::setPhi_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActServo::setPhi_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActServo::setPhi_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActServo::setPhi_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActServo::setPhi_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActServo::setPhi_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActServo::setPhi_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActServo::setTheta_req> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActServo::setTheta_req";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActServo::setTheta_req> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActServo::setTheta_req> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActServo::setTheta_req& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActServo::setTheta_req& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActServo::setTheta_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActServo::setTheta_req& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActServo::setTheta_reply> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActServo::setTheta_reply";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActServo::setTheta_reply> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActServo::setTheta_reply> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActServo::setTheta_reply& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActServo::setTheta_reply& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActServo::setTheta_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActServo::setTheta_reply& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name<DdsJobMsdcActServo::thetaPhi> {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobMsdcActServo::thetaPhi";
            }
        };

        template<>
        struct is_topic_type<DdsJobMsdcActServo::thetaPhi> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DdsJobMsdcActServo::thetaPhi> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DdsJobMsdcActServo::thetaPhi& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobMsdcActServo::thetaPhi& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DdsJobMsdcActServo::thetaPhi& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobMsdcActServo::thetaPhi& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<tinyint_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<utinyint_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<smallint_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<usmallint_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<_cxx_int_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<uint_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<bigint_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<ubigint_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<vecsref_AliasTag_t> {
            typedef dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqAdxl::alphaBeta> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqAdxl::alphaBeta> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqLwir::setOutput_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqLwir::setOutput_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqLwir::setOutput_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqLwir::setOutput_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqLwir::start_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqLwir::start_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqLwir::start_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqLwir::start_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqLwir::stop_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqLwir::stop_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqLwir::stop_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqLwir::stop_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqLwir::seqnoTGray16> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqLwir::seqnoTGray16> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::setFocus_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::setFocus_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::setFocus_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::setFocus_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::setOutput_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::setOutput_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::setOutput_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::setOutput_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::setTint_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::setTint_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::setTint_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::setTint_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::start_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::start_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::start_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::start_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::stop_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::stop_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::stop_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::stop_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::setFocus_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::setFocus_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::setFocus_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::setFocus_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::setOutput_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::setOutput_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::setOutput_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::setOutput_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::setTint_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::setTint_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::setTint_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::setTint_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::start_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::start_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::start_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::start_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::stop_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::stop_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::stop_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::stop_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActAlign::setWave_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActAlign::setWave_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActAlign::setWave_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActAlign::setWave_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActAlign::start_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActAlign::start_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActAlign::start_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActAlign::start_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActAlign::stop_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActAlign::stop_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActAlign::stop_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActAlign::stop_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActLed::setFlood_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActLed::setFlood_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActLed::setFlood_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActLed::setFlood_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActLed::setSpot_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActLed::setSpot_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActLed::setSpot_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActLed::setSpot_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActLed::floodSpot> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActLed::floodSpot> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActServo::setPhi_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActServo::setPhi_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActServo::setPhi_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActServo::setPhi_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActServo::setTheta_req> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActServo::setTheta_req> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActServo::setTheta_reply> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActServo::setTheta_reply> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DdsJobMsdcActServo::thetaPhi> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DdsJobMsdcActServo::thetaPhi> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // DdsMsdc_1182983940_hpp

