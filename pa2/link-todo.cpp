#include "link.h"

//// TODO: complete the member function defintions of LinkImpl and LinkProxy

LinkImpl::LinkImpl(LinkType link_type, LinkProperties properties): Link(link_type), properties_(properties){}

bool LinkImpl::IsBuilt() const {
  return this->adj_ != nullptr;
}

bool LinkImpl::Build(Link* link) {
    if (CanOverbuild(link)) {
      this->adj_ = link->adjacency();
      link->BeOverbuilt(this);
      this->set_player(link->player());
      return true;
  }
  return false;
}

bool LinkImpl::CanOverbuild(Link* link) const {
  if(link == nullptr || link->player() == nullptr){
    return true;
  }
  return false;
}

int LinkImpl::vp() const {
  return this->adj_ == nullptr ? 0 : this->adj_->vp_for_link();
}

LinkProperties LinkImpl::properties() const {
  return properties_;
}

Player* LinkImpl::player() const {
  return this->player_;
}

std::string LinkImpl::player_name() const {
  if (player_ != nullptr) {
    return player_->name();
  }
  return kEmptyPlayerName;
}

void LinkImpl::set_player(Player* player) {
  this->player_ = player;
}

void LinkImpl::set_observer(LinkObserver* observer){}

LinkProxy::LinkProxy(LinkType link_type, Adjacency* adj):Link(link_type, adj){};

bool LinkProxy::IsBuilt() const {
  return (this->impl_ != nullptr && (this->impl_->IsBuilt()));
}

bool LinkProxy::Build(Link* link) {
  return false;
}

bool LinkProxy::CanOverbuild(Link* link) const {
  return false;
}

void LinkProxy::BeOverbuilt(Link* link) {
  if (impl_ != nullptr) {
    impl_->BeOverbuilt(link);
  }
  impl_ = static_cast<LinkImpl*>(link);
}

int LinkProxy::vp() const {
  return (impl_ == nullptr)? 0 : impl_->vp();
}

LinkProperties LinkProxy::properties() const {
  if (impl_ != nullptr) {
    return impl_->properties();
  }
  return {};
}

Player* LinkProxy::player() const {
  return (impl_ == nullptr)? nullptr : impl_->player();
}
std::string LinkProxy::player_name() const{
  return this->impl_ != nullptr ? this->impl_->player_name() : kEmptyPlayerName;
}
  // returns kEmptyPlayerName if not available

void LinkProxy::set_player(Player* player) {
  if(this->impl_ == nullptr){
    this->impl_->set_player(player);
  }
}
void LinkProxy::set_observer(LinkObserver* observer){
  this->observer_ = observer;
}

//// TODO ends
